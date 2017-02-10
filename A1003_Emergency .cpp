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
const int maxn=510,inf=1e9;
bool vis[maxn]={false};

int d[maxn],w[maxn],num[maxn];
int n,m,s,t,weight[maxn];
struct node{
	int v,dis;
	node(int _v,int _dis):v(_v),dis(_dis){}
};
vector<node> adj[maxn];
set<int> pre[maxn];
void bf(int s){
	fill(d,d+maxn,inf);
	d[s]=0;
	memset(w,0,sizeof(w));
	w[s]=weight[s];/////////////////
	fill(num,num+maxn,0);
	num[s]=1;
	for(int i=0;i<n-1;i++){
		for(int u=0;u<n;u++){
			for(int j=0;j<adj[u].size();j++){
				int v=adj[u][j].v;//////////////////////////
				int dis=adj[u][j].dis;
				if(d[u]+dis<d[v]){
					d[v]=d[u]+dis;
					num[v]=num[u];////////////////////////////
					w[v]=weight[v]+w[u];/////////////
					pre[v].clear();
					pre[v].insert(u);

				}else if(d[u]+dis==d[v]){
					//num[v]+=num[u];
					if(w[u]+weight[v]>w[v]){///////////
						w[v]=w[u]+weight[v];
					}
					pre[v].insert(u);
					num[v]=0;
					set<int>::iterator it;
					for(it=pre[v].begin();it!=pre[v].end();it++){
						num[v] += num[*it];
					}

				}
			}
		}
	}
}
int main(){
	freopen("G:\\PATdata\\A1003.txt","r",stdin);
	cin>>n>>m>>s>>t;
	memset(adj,inf,sizeof(adj));
	for(int i=0;i<n;i++){
		cin>>weight[i];
	}
	int u,y,wt;
	for(int i=0;i<m;i++){
		cin>>u>>y>>wt;
		adj[u].push_back(node(y,wt));
		adj[y].push_back(node(u,wt));
	}
	bf(s);
	cout<<num[t]<<" "<<w[t]<<endl;//////////w[t]¶ø²»ÊÇweight[t]

	return 0;
}