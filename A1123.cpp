#include<cstdio>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
struct node{
	int v,height;
	node* lch,*rch;
}*root,*null;///////////////////////////
node* newnode(int v){
	node* t=new node();
	t->v=v;
	t->height=1;		/////////////////////  1 
	t->lch=t->rch=null;/////////////////
	return t;
}
void getNewHeight(node* root){
	root->height=max(root->lch->height,root->rch->height)+1;
}
void L(node* &root){
	node* tmp=root->rch;
	root->rch=tmp->lch;
	tmp->lch=root;
	getNewHeight(root);
	getNewHeight(tmp);
	root=tmp;
}
void R(node* &root){
	node* tmp=root->lch;
	root->lch=tmp->rch;
	tmp->rch=root;
	getNewHeight(root);
	getNewHeight(tmp);
	root=tmp;
}
void insert(node* &root,int v){
	if(root==null){    			/////////////////////
		root=newnode(v);		/////////////////////node* ≤ª”√ 
		return;
	}
	if(v<root->v){
		insert(root->lch,v);
		getNewHeight(root);
		if(root->lch->height - root->rch->height==2){
			if(root->lch->lch->height - root->lch->rch->height==1){
				R(root);
			}else if(root->lch->lch->height - root->lch->rch->height==-1){
				L(root->lch);
				R(root);
			}
		}
	}else{
		insert(root->rch,v);
		getNewHeight(root);
		if(root->lch->height - root->rch->height==-2){
			if(root->rch->lch->height - root->rch->rch->height==-1){
				L(root);
			}else if(root->rch->lch->height - root->rch->rch->height==1){
				R(root->rch);
				L(root);
			}
		}
	}
}
void init(){
	null=new node;
	null->height=0;//////////////////////////
	root=null;
}
int n,v;
int cnt=0;
void bfs(node* root){
	queue<node*> q;
	q.push(root);
	while(!q.empty()){
		node* now=q.front();
		q.pop();
		cout<<now->v;
		cnt++;
		if(cnt<n)
			cout<<" ";
		if(now->lch!=null){
			q.push(now->lch);	
		}else{
			now->lch->v=-1;
		}
		if(now->rch!=null){
			q.push(now->rch);
		}else{
			now->rch->v=-1;
		}
	}
}
int num=0;
void BFS2(node* root){
	queue<node*> q;
	q.push(root);
	while(!q.empty()){
		node* now=q.front();
		q.pop();
		if(now->v!=-1)
			num++;
		if(now->v==-1)
			break;
		q.push(now->lch);
		q.push(now->rch);
	}
}

int main(){
	
	init();
	//freopen("G:\\PATdata\\A1123.txt","r",stdin);
	cin>>n;
		for(int i=0;i<n;i++){
			cin>>v;
			insert(root,v);
		}
		bfs(root);
		cout<<endl;
		BFS2(root);
		if(num==n)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	
	return 0;
}
