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
const int maxn=101;
struct Node{
	int weight;
	vector<int> ch;
}node[maxn];
bool cmp(int a,int b){
	return node[a].weight>node[b].weight;
}
int n,m,s;
int path[maxn];
void dfs(int index,int numnode,int sum){
	if(sum>s)
		return;
	if(sum==s){////////////////////////////////////////
		if(node[index].ch.size()!=0)
			return;
		for(int i=0;i<numnode;i++){
			printf("%d",node[path[i]].weight);
			if(i<numnode-1)
				printf(" ");
			else
				printf("\n");
		}
		return;
	}
	for(int i=0;i<node[index].ch.size();i++){
		int child=node[index].ch[i];
		path[numnode]=child;

		dfs(child,numnode+1,sum+node[child].weight);///////////
	}
}
int main(){
		freopen("G:\\PATdata\\A1053.txt","r",stdin);
	cin>>n>>m>>s;
	for(int i=0;i<n;i++){
		cin>>node[i].weight;
	}
	int id,k,child;
	for(int i=0;i<m;i++){
		cin>>id>>k;
		for(int j=0;j<k;j++){
			cin>>child;
			node[id].ch.push_back(child);
		}
		sort(node[id].ch.begin(),node[id].ch.end(),cmp);
	}
	path[0]=0;
	dfs(0,1,node[0].weight);////////////
	return 0;
}