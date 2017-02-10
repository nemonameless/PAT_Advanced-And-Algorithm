#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
const int maxn=1001,INF=1e9;
int g[maxn][maxn],d[maxn],h[maxn];
bool vis[maxn]={false};
int n,m,s,t;
int hand[maxn],num[maxn];
void dijkstra(int s){
	fill(d,d+maxn,INF);
	d[s]=0;

	fill(h,h+maxn,0);////////////////0¶ø²»ÊÇ-1
	h[s]=hand[s];

	fill(num,num+maxn,0);
	num[s]=1;

	for(int i=0;i<n;i++){
		int u=-1,min=INF;
		for(int j=0;j<n;j++){
			if(d[j]<min &&vis[j]==false){
				u=j;
				min=d[j];
			}
		}
		if(u==-1)
			return;
		vis[u]=true;
		for(int v=0;v<n;v++){
			if(vis[v]==false  && g[u][v]!=INF ){////////
				if(d[u]+g[u][v]<d[v]){
					d[v]=d[u]+g[u][v];
					num[v] = num[u];
					h[v]=h[u]+hand[v];
				}else if(d[u]+g[u][v]==d[v]){
					num[v]+= num[u];
					if(h[u]+hand[u]>h[v]){
						h[v]=h[u]+hand[v];
					}
				}
			}
		}
	}
}

int main(){
	freopen("G:\\PATdata\\A1003.txt","r",stdin);
	cin>>n>>m>>s>>t;
	fill(g[0],g[0]+maxn*maxn,INF);
	for(int i=0;i<n;i++){
		cin>>hand[i];
	}
	int u,v,w;
	for(int i=0;i<m;i++){
		cin>>u>>v>>w;
		g[u][v]=w;
		g[v][u]=w;
	}
	dijkstra(s);
	cout<<num[t]<<" "<<h[t]<<endl;

	return 0;
}

