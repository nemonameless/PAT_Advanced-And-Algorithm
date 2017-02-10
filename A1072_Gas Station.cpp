#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<cctype>
#include<algorithm>
#include<cmath>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<stack>
using namespace std;
const int maxn=1015,inf=1e9;
int g[maxn][maxn],d[maxn];
int n,m,k,ds;
bool vis[maxn]={false};
void dijk(int s){
	memset(vis, false, sizeof(vis));/////////////////
	fill(d,d+maxn,inf);
	d[s]=0;
	for(int i=0;i<n+m;i++){
		int u=-1,min=inf;
		for(int j=1;j<=m+n;j++){
			if(d[j]<min && vis[j]==false){
				u=j;
				min=d[j];
			}
		}
		if(u==-1) 
			return;
		vis[u]=true;
		for(int v=1;v<=m+n;v++){
			if(vis[v]==false && d[u]+g[u][v]<d[v]&& g[u][v]!=inf){
				d[v]=d[u]+g[u][v];
			}
		}
	}
}
int getid(char c[]){
	int ans=0,i=0;
	int len=strlen(c);
	if(c[0]=='G')
		i++;
	while(i<len){
		ans=ans*10+c[i]-'0';
		i++;
	}
	if(c[0]=='G')
		return ans+n;
	else
		return ans;

}

int main(){
	freopen("G:\\PATdata\\A1072.txt","r",stdin);
	cin>>n>>m>>k>>ds;
	fill(g[0],g[0]+maxn*maxn,inf);
	char a[6],b[6];
	int u,v;
	for(int i=0;i<k;i++){/////////////////////
		cin>>a>>b;
		u=getid(a);
		v=getid(b);
		cin>>g[u][v];
		g[v][u]=g[u][v];
	}
	int ansid=-1;
	double ansdis=-1,ansavg=inf;////////////////////////////
	for(int i=n+1;i<=n+m;i++){
		double mindis=inf,avg=0;/////////////////
		dijk(i);
		for(int j=1;j<=n;j++){
			if(d[j]>ds){
				mindis=-1;
				break;
			}
			if(d[j]<mindis){
				mindis=d[j];
			}
			avg+=d[j]*1.0/n;
		}
		if(mindis==-1){//////////////////////
			continue;
		}
		if(mindis>ansdis){     ////////´óÓÚ
			ansdis=mindis;
			ansid=i;
			ansavg=avg;
		}else if(mindis==ansdis && ansavg>avg){     //////////<
			ansid=i;
			ansavg=avg;
		}
	}
	if(ansid == -1) printf("No Solution\n");
    else {
        printf("G%d\n", ansid - n);
        printf("%.1f %.1f\n", ansdis, ansavg);
    }


	return 0;
}