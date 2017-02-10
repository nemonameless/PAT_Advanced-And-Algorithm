#include<cstdio>
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
int g[maxn][maxn],d[maxn],t[maxn],T[maxn][maxn];
bool vis[maxn]={false};
vector<int> pre[maxn],tmp,ans1,ans2;
int n,m,way,len,ti,st,ed;

void dijk(int g[][maxn],int d[]){
	fill(d,d+maxn,inf);
	memset(vis, false, sizeof(vis));  
	d[st]=0;
	
	for(int i=0;i<n;i++)////////////////////不加也能过，但最好加上
		pre[i].push_back(i);

	for(int i=0;i<n;i++){
		int u=-1,min=inf;
		for(int j=0;j<n;j++){
			if(d[j]<min && vis[j]==false){
				u=j;
				min=d[j];
			}
		}
		if(u==-1)
			return;
		vis[u]=true;
		for(int v=0;v<n;v++){
			if(vis[v]==false && g[u][v]!=inf){
				if(d[u]+g[u][v]<d[v]){
					d[v]=d[u]+g[u][v];
					pre[v].clear();
					pre[v].push_back(u);
				}else if(d[u]+g[u][v]==d[v])
					pre[v].push_back(u);
			}
		}	
	}
}
int mint=inf,minvtx=inf;
void dfs1(int v){
	if(v==st){
		tmp.push_back(v);
		int tmpt=0;
		for(int i=tmp.size()-1;i>0;i--){/////////////////////tmp.size()
			int id=tmp[i],idnext=tmp[i-1];
			tmpt+=T[id][idnext];
		}
		if(tmpt<mint){
			mint=tmpt;
			ans1=tmp;
		}
		tmp.pop_back();
		return;
	}
	tmp.push_back(v);
	for(int i=0;i<pre[v].size();i++){
		dfs1(pre[v][i]);
	}
	tmp.pop_back();
}
void printpath(vector<int> tmp){
	for(int i=tmp.size()-1;i>=0;i--){
		cout<<tmp[i];
		if(i>0)
			cout<<" -> ";
		else
			cout<<endl;
	}
}
void dfs2(int v){
	if(v==st){
		tmp.push_back(v);
		if(ans2.size()==0 || ans2.size()>tmp.size())
			ans2=tmp;//////////////////
		tmp.pop_back();///////////////////////////
		return;
	}
	tmp.push_back(v);
	for(int i=0;i<pre[v].size();i++){
		dfs2(pre[v][i]);
	}
	tmp.pop_back();
}
int main(){
	//freopen("G:\\PATdata\\A1111.txt","r",stdin);
fill(g[0],g[0]+maxn*maxn,inf);/////////////////////////////////
	fill(T[0],T[0]+maxn*maxn,inf);
	cin>>n>>m;
	int u,v;
	
	for(int i=0;i<m;i++){
		cin>>u>>v>>way>>len>>ti;
		g[u][v]=len;
		T[u][v]=ti;
		if(way==0){
			g[v][u]=len;
			T[v][u]=ti;
		}
	}
	cin>>st>>ed;
	dijk(g,d);
	dfs1(ed);

	dijk(T,t);
	dfs2(ed);
	if(ans1==ans2){
		cout<<"Distance = "<<d[ed]<<"; Time = "<<t[ed]<<": ";/////////////
		printpath(ans1);
	}else{
		cout<<"Distance = "<<d[ed]<<": ";////////////////
		printpath(ans1);

		cout<<"Time = "<<t[ed]<<": ";////////////////////小心格式，要复制题目里的，不要自己YY
		printpath(ans2);
	}
	return 0;
}
