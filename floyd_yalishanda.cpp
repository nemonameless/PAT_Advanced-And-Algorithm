#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
const int maxn=1001,INF=1e9;
int dis[maxn][maxn];
int n,m;
void floyd(){
	for(int k=0;k<n;k++){
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(dis[i][k]+dis[k][j] < dis[i][j] && dis[i][k]!=INF &&dis[k][j]!=INF)
					dis[i][j] =dis[i][k]+dis[k][j] ;
			}
		}
	}
}
int t;
int main(){
	int u,v,w;
	freopen("G:\\PATdata\\yalishanda2.txt","r",stdin);
	fill(dis[0],dis[0]+maxn*maxn,INF);
	
	cin>>n>>m;
for(int i=0;i<n;i++){
		dis[i][i]=0;
	}

	for(int i=0;i<m;i++){
		cin>>u>>v>>w;
		dis[u][v]=w;
	}
	floyd();
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout<<dis[i][j]<<" ";		
		}
		cout<<endl;
	}
	return 0;
}

