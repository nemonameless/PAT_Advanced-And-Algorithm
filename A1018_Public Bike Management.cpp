#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
using namespace std;
const int maxn=510,inf=1e9;
bool vis[maxn]={false};
int d[maxn],g[maxn][maxn],weight[maxn];
vector<int> tmp,ans,pre[maxn];
int minneed=inf,minremain=inf;
int cmax,n,ed,m;
void dijk(int s){
	fill(d,d+maxn,inf);
	d[s]=0;
	for(int i=0;i<=n;i++){
		pre[i].push_back(i);
	}
	for(int i=0;i<=n;i++){////////////////////////i<n
		int u=-1,min=inf;
		for(int j=0;j<=n;j++){
			if(vis[j]==false && d[j]<min){
				u=j;
				min=d[j];
			}
		}
		if(u==-1)
			return;
		vis[u]=true;
		for(int v=0;v<=n;v++){//////////////////////////////
			if(vis[v]==false && g[u][v]!=inf){
				if(d[u]+g[u][v]<d[v]){
					d[v]=d[u]+g[u][v];
					pre[v].clear();
					pre[v].push_back(u);
				}else if(d[u]+g[u][v]==d[v]){
					pre[v].push_back(u);
				}
			}
		}
	}
}
void dfs(int v){
	if(v==0){
		tmp.push_back(v);
		int need=0,remain=0;
		for(int i=tmp.size()-1;i>=0;i--){
			int id=tmp[i];
			if(weight[id]>0){
				remain+=weight[id];
			}else{
				if(remain-abs(weight[id])>0){
					remain-=abs(weight[id]);
				}else{
					need+=abs(weight[id])-remain;
					remain=0;///////////////////////////
				}
			}
		}
		if(need<minneed){
			minneed=need;/////////////////////
			minremain=remain;
			ans=tmp;
		}else if(need==minneed && remain<minremain){
			minremain=remain;
			ans=tmp;
		}
		tmp.pop_back();
		return;
	}
	tmp.push_back(v);
	for(int i=0;i<pre[v].size();i++){//////////////////////²»ÊÇtmp.size
		dfs(pre[v][i]);
	}
	tmp.pop_back();
}
int main(){
	cin>>cmax>>n>>ed>>m;
	fill(g[0],g[0]+maxn*maxn,inf);//////////
	for(int i=1;i<=n;i++){
		cin>>weight[i];
		weight[i]-=cmax/2;
	}
	int u,v;
	for(int i=0;i<m;i++){
		cin>>u>>v;
		cin>>g[u][v];
		g[v][u]=g[u][v];
	}
	dijk(0);
	dfs(ed);
	cout<<minneed<<" ";
	for(int i=ans.size()-1;i>=0;i--){
		cout<<ans[i];
		if(i>0)
			cout<<"->";
	}
	cout<<" "<<minremain<<endl;
	return 0;
}
