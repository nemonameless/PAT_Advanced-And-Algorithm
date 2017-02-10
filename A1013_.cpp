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
const int maxn=1010;
vector<int> g[maxn];
bool vis[maxn]={false};
int deleted;
void dfs(int v){
	if(v==deleted)
		return;
	vis[v]=true;
	for(int i=0;i<g[v].size();i++){
		if(vis[g[v][i]]==false)////////////////////////////////////
			dfs(g[v][i]);
	}
}
int main(){
	int n,m,k;

	freopen("G:\\PATdata\\A1013.txt","r",stdin);
	cin>>n>>m>>k;
	int u,v;
	for(int i=0;i<m;i++){
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	for(int j=0;j<k;j++){
		cin>>deleted;
		memset(vis,false,sizeof(vis));/////////////////////////
		int block=0;
		for(int i=1;i<=n;i++){
			if(i!=deleted && vis[i]==false){///////////////////////////
				dfs(i);
				block++;
			}
		}
		cout<<block-1<<endl;/////////////
	}

	return 0;
}