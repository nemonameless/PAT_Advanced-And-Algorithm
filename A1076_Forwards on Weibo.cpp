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
const int maxn=1001;
bool inq[maxn]={false};
struct node{
	int id,layer;
};
vector<node> g[maxn];
int BFS(int s,int L){
	int numForward=0;
	queue<node> q;
	node start;
	start.id=s;
	start.layer=0;/////////////////
	q.push(start);
	inq[start.id]=true;
	while(!q.empty()){
		node topnode=q.front();
		q.pop();
		int u=topnode.id;
		for(int i=0;i<g[u].size();i++){		///////////////////// 
			node next=g[u][i];
			next.layer=topnode.layer+1;
			if(inq[next.id]==false && next.layer<=L){////////////////
				q.push(next);
				inq[next.id]=true;
				numForward++;
			}
		}
	}
	return numForward;
}
int main(){
	int n,L;
	//freopen("G:\\PATdata\\A1076.txt","r",stdin);
	cin>>n>>L;
	int k,id,q,s;
	node user;
	for(int i=1;i<=n;i++){
		cin>>k;
		user.id=i;////////////²»ÊÇ=id  //////////////////// //////////////////// //////////////////// //////////////////// //////////////////// 
	
			for(int j=0;j<k;j++){
				cin>>id;
				g[id].push_back(user);/////////////////////////////// 
			}
		
	}
	cin>>q;
	for(int i=0;i<q;i++){
		memset(inq,false,sizeof(inq));///////////////////// 
		cin>>s;
		int numf=BFS(s,L);
		cout<<numf<<endl;
	}

	return 0;
}
