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
const int maxn=20002;
vector<int> g[maxn];
int father[maxn]={};
bool isroot[maxn]={false};
int n;
void init(int n){
	for(int i=1;i<=n;i++)
		father[i]=i;
}
int findFather(int x){
	while(x!=father[x])
		x=father[x];
	return x;
}
void Union(int a,int b){
	int faa=findFather(a),fab=findFather(b);
	if(faa!=fab)
		father[faa]=fab;
}

int CalBlock(int n){
	int block=0;
	for(int i=1;i<=n;i++){
		isroot[findFather(i)]=true;
	}
	for(int i=1;i<=n;i++){
		block+=isroot[i];
	}
	return block;
}
int maxh=0;
set<int> tmp,ans;
void dfs(int u,int height,int pre){
	if(height>maxh){
		tmp.clear();
		tmp.insert(u);
		maxh=height;
	}else if(height==maxh){
		tmp.insert(u);
	}
	for(int i=0;i<g[u].size();i++){
		if(g[u][i]==pre)
			continue;
		dfs(g[u][i],height+1,u);
	}
}

int main(){
	freopen("G:\\PATdata\\A1021.txt","r",stdin);
	scanf("%d",&n);
	init(n);
	int a,b;
	for(int i=0;i<n-1;i++){/////////////////5 但输入是4行，保证n个点n-1条边
		
		scanf("%d%d",&a,&b);
		g[a].push_back(b);
		g[b].push_back(a);
		Union(a,b);
	}
	int Block=CalBlock(n);
	if(Block!=1){
		printf("Error: %d components\n",Block);
	}else{
		dfs(1,1,-1);
		ans=tmp;
		set<int>::iterator it;
		it=ans.begin();
		dfs(*it,1,-1);          //////////////////////////
		for(it=tmp.begin();it!=tmp.end();it++){
			ans.insert(*it);///////////////////////////
		}
		for(it=ans.begin();it!=ans.end();it++){
			printf("%d\n",*it);
		}
	}

	return 0;
}