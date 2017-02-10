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
struct node{
	int data,layer;
	node* lch,*rch;
};
void insert(node* &root,int data){////////////////&
	if(root==NULL){
		root=new node;
		root->data=data;///////////////////////////////
		root->lch=root->rch=NULL;
		return;
	}
	if(data<=root->data)
		insert(root->lch,data);
	else
		insert(root->rch,data);//////////复制过来别忘记改
}

void bfs(node* root){
	queue<node*> q;
	q.push(root);
	root->layer=1;
	while(!q.empty()){
		node* top=q.front();
		q.pop();
	//	printf("%d ",top->data);
		if(top->lch!=NULL){
			q.push(top->lch);
			top->lch->layer=top->layer+1;
		}
		if(top->rch!=NULL){
			q.push(top->rch);
			top->rch->layer=top->layer+1;
		}
	}
}
int ans=0;
void dfs(node* root,int depth){
	if(root==NULL)
		return;
	if(depth>ans)
		ans=depth;
	dfs(root->lch,depth+1);
	dfs(root->rch,depth+1);
}
int cnt[2]={};
void bfs2(node* root){
	queue<node*> q;
	q.push(root);
	while(!q.empty()){
		node* top=q.front();
		q.pop();
		if(top->layer==ans-1)
			cnt[0]++;
		if(top->layer==ans)
			cnt[1]++;

		if(top->lch!=NULL){
			q.push(top->lch);
		}
		if(top->rch!=NULL){
			q.push(top->rch);
		}
	}
}
int main(){
	int n;
 	freopen("G:\\PATdata\\A1115.txt","r",stdin);
	cin>>n;
	int data;
	node* root=NULL;
	for(int i=0;i<n;i++){
		cin>>data;
		insert(root,data);
	}
	bfs(root);
	dfs(root,1);
	bfs2(root);
	//printf("%d\n",ans);
	
	printf("%d + %d = %d\n",cnt[1],cnt[0],cnt[0]+cnt[1]);/////写反的话扣28分

	return 0;
}