#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
struct node{
	int v,height;
	node* lch,*rch;
}*root,*null;///////////////////////////
node* newnode(int v){
	node* t=new node();
	t->v=v;
	t->height=1;		////////////////	t->height=1;	
	t->lch=t->rch=null;/////////////////
	return t;
}
void getNewHeight(node* root){
	root->height=max(root->lch->height,root->rch->height)+1;
}
void L(node* &root){
	node* tmp=root->rch;////////////////////l R
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
	if(root==null){    /////////////////////
		root=newnode(v);		////////////////≤ª”√node* root 
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
	null=new node;///////////////////////not new node() 
	null->height=0;						////////	null->height=0;
	root=null;	///////////////////
}
int main(){
	int n,v;
	init();
	freopen("G:\\PATdata\\A1066.txt","r",stdin);
	cin>>n;
	
		for(int i=0;i<n;i++){
			cin>>v;
			insert(root,v);
		}
		cout<<root->v<<endl;
	
	return 0;
}
