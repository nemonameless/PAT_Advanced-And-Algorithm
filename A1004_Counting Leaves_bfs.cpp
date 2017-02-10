
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
const int maxn=110;
vector<int> g[maxn];
int n,m;
int maxh=1;
int leaf[maxn]={},h[maxn]={};
void bfs(){
	queue<int> q;
	q.push(1);/////////////////////////
	while(!q.empty()){
		int id=q.front();
		q.pop();
		maxh=max(maxh,h[id]);
		if(g[id].size()==0)
			leaf[h[id]]++;
		for(int i=0;i<g[id].size();i++){
			h[g[id][i]]=h[id]+1;//////////////////////
			q.push(g[id][i]);
		}		
	}
}

int main(){
	freopen("G:\\PATdata\\A1004.txt","r",stdin);
	cin>>n>>m;
	int parent,k,child;
	for(int i=0;i<m;i++){
		cin>>parent>>k;
		for(int j=0;j<k;j++){
			cin>>child;
			g[parent].push_back(child);
		}
	}
	h[1]=1;
	bfs();
	cout<<leaf[1];
	for(int i=2;i<=maxh;i++){
		cout<<" "<<leaf[i];
	}

	return 0;
}
