
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
const int maxn=110;
vector<int> g[maxn];
int has[maxn]={};
int n,m;
void dfs(int index,int level){////////////////////////////不用递归边界
	has[level]++;//////////////////////////////////不是index
	for(int j=0;j<g[index].size();j++){
		dfs(g[index][j],level+1);
	}
}
int main(){
	//freopen("G:\\PATdata\\A1094.txt","r",stdin);
	cin>>n>>m;
	int k,parent,child;
	for(int i=0;i<m;i++){
		cin>>parent>>k;
		for(int j=0;j<k;j++){
			cin>>child;
			g[parent].push_back(child);
		}
	}
	dfs(1,1);
	int maxNodeNum=0,maxLevel=-1;
	for(int i=1;i<maxn;i++){
		if(has[i]>maxNodeNum){
			maxNodeNum=has[i];
			maxLevel=i;
		}
	}
	cout<<maxNodeNum<<" "<<maxLevel<<endl;

	return 0;
}
