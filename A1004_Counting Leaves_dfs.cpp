#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
const int maxn=110;
vector<int> g[maxn];
int n,m;
int maxh=1;
int leaf[maxn]={};
void dfs(int index,int h){
	maxh=max(h,maxh);
	if(g[index].size()==0){
		leaf[h]++;
		return;
	}
	for(int i=0;i<g[index].size();i++){
		dfs(g[index][i],h+1);
	}
}

int main(){
	//freopen("G:\\PATdata\\A1004.txt","r",stdin);
	cin>>n>>m;
	int parent,k,child;
	for(int i=0;i<m;i++){
		cin>>parent>>k;
		for(int j=0;j<k;j++){
			cin>>child;
			g[parent].push_back(child);
		}
	}
	dfs(1,1);
	cout<<leaf[1];
	for(int i=2;i<=maxh;i++){
		cout<<" "<<leaf[i];
	}

	return 0;
}
