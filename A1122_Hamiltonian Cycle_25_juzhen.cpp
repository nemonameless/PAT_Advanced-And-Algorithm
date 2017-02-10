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
const int maxn=220,inf=1e9;
int g[maxn][maxn];
int in[maxn]={},t[maxn]={};
int main(){
	int n,m;
	//freopen("G:\\PATdata\\A1122.txt","r",stdin);
	scanf("%d%d",&n,&m);
	int a,b;
	fill(g[0],g[0]+maxn*maxn,inf);
	for(int i=0;i<m;i++){
		scanf("%d%d",&a,&b);
		g[a][b]=1;
		g[b][a]=1;
	}
	int k;
	int q;
	scanf("%d",&q);
	for(int i=1;i<=q;i++){
		memset(in,0,sizeof(in));
		scanf("%d",&k);
		for(int j=0;j<k;j++){
			scanf("%d",&t[j]);
			in[t[j]]=1;
		}
		int th=0;
		for(int j=1;j<=n ;j++){
			if(in[j]!=1){
				th=1;
				break;
			}
		}
		if(k!=n+1  || t[0]!=t[k-1] || th==1){
			printf("NO\n");
		}else{
			int flag=0;
			for(int j=0;j<k-1;j++){
				if(g[t[j]][t[j+1]]!=1){
					flag=1;
					break;
				}
			}
			if(flag!=0)
					printf("NO\n");
				else
					printf("YES\n");
		}
	}
	return 0;
}