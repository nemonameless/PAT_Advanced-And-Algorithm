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
int nowp;
void dfs(int v){
	if(v==nowp)
		return;
	vis[v]=true;
	for(int i=0;i<g[v].size();i++){
		if(vis[g[v][i]]==false)
			dfs(g[v][i]);
	}
}
int main(){
	int n,m,k;
	//freopen("G:\\PATdata\\A1013.txt","r",stdin);
	cin>>n>>m>>k;
	for(int i=0;i<m;i++){
		int a,b;
		cin>>a>>b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	for(int q=0;q<k;q++){
		cin>>nowp;
		memset(vis,false,sizeof(vis));///////////////
		int block=0;
		for(int i=1;i<=n;i++){/////////////////////
			if(i!=nowp && vis[i]==false){/////////////////////////////////////
				dfs(i);
				block++;
			}
		}
		cout<<block-1<<endl;/////////////使无向图连通需增加的边数等于连通块个数-1
	}

	return 0;
}