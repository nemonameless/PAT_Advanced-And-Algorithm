#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
const int maxn=1001,INF=1e9;
int g[maxn][maxn];
int d[maxn];
bool vis[maxn]={false};
int n,m,s;
int pre[maxn];
void dijkstra(int s){
	fill(d,d+maxn,INF);
	d[s]=0;
	for(int i=0;i<n;i++){
		pre[i]=i;
	}
	for(int i=0;i<n;i++){
		int u=-1,min=INF;
		for(int j=0;j<n;j++){
			if(vis[j]==false && d[j]<min){
				u=j;
				min=d[j];
			}
		}
		if(u==-1)
			return;
		vis[u]=true;
		for(int v=0;v<n;v++){	
			if(vis[v]==false && g[u][v]!=INF && d[u]+g[u][v]<d[v]){
				d[v]=d[u]+g[u][v];
				pre[v]=u;
			}
		}
	}
}
void dfs(int s,int v){
	if(v==s){
		cout<<s<<"-";
		return;
	}
	dfs(s,pre[v]);
	cout<<v<<"-";
}
int t;
int main(){
	int u,v,w;
	freopen("G:\\PATdata\\yalishanda.txt","r",stdin);
	fill(g[0],g[0]+maxn*maxn,INF);
	cin>>n>>m>>s>>t;
	for(int i=0;i<m;i++){
		cin>>u>>v>>w;
		g[u][v]=w;
	}
	dijkstra(s);
	for(int i=0;i<n;i++){
		cout<<d[i];
		if(i<n-1)
			cout<<" ";
		else
			cout<<endl;
	}
	dfs(s,t);////////////////////

	return 0;
}

