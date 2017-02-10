#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<queue>
using namespace std;
const int maxn=201;
struct Node{
	int id,lch,rch;
}node[maxn];
int n,num=0,que[maxn]={};
int cnt=0;
int last;
void BFS(int root){
	queue<int> q;
	q.push(root);
	while(!q.empty()){
		int now=q.front();
		q.pop();		
		if(now!=-1){		
			cnt++;//访问过结点的数目。
			last=now;	////最后一个结点。  
		}
		if(now==-1)
			break;
		q.push(node[now].lch);////////BFS与层序遍历是不一样的概念
		q.push(node[now].rch);
	}
}
bool notroot[maxn]={false};
int main(){
    char s1[5],s2[5];  
	freopen("G:\\PATdata\\A1110.txt","r",stdin);
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		node[i].lch=node[i].rch=-1;
	}

	for(int i=0;i<n;i++){
		scanf("%s %s",s1,s2);
		if(s1[0]!='-'){
			sscanf(s1,"%d",&node[i].lch);
			notroot[node[i].lch]=true;
		}else{
			node[i].lch=-1;
		}
		if(s2[0]!='-'){
			sscanf(s2,"%d",&node[i].rch);
			notroot[node[i].rch]=true;
		}else{
			node[i].rch=-1;
		}
	}
	int root=-1;
	for(int i=0;i<n;i++){
		if(notroot[i]==false){
			root=i;
			break;
		}
	}
	cnt=0;
	BFS(root);
	if(cnt==n)
		printf("YES %d\n",last);  
	else
		printf("NO %d\n",root);  

	return 0;
}