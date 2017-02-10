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
const int maxn=31;
int in[maxn];
struct node{
	int data;
	node* lch,*rch;
}nd[maxn];
vector<int> pre,post,layer;
int n;
node* create(vector<int> layer,int inl,int inr){
	if(layer.size()==0)
		return NULL;
	node* root=new node;
	root->data=layer[0];
	root->lch=root->rch=NULL;
	int k;
	for(k=inl;k<=inr;k++){
		if(in[k]==layer[0])
			break;
	}

	vector<int> layerleft,layerright;
	for(int i=1;i<layer.size();i++){///////////////从1开始
		bool isleft=false;
		for(int j=inl;j<k;j++){
			if(layer[i]==in[j]){
				isleft=true;
				break;
			}
		}
		if(isleft)
			layerleft.push_back(layer[i]);
		else
			layerright.push_back(layer[i]);
	}
	root->lch=create(layerleft,inl,k-1);
	root->rch=create(layerright,k+1,inr);
	return root;
}
void preod(node* root){      ///////////preod中不可把pre写在函数列表做形参
	if(root==NULL)
		return;
	pre.push_back(root->data);
	preod(root->lch);
	preod(root->rch);
}
void postod(node* root){
	if(root==NULL)
		return;
	postod(root->lch);
	postod(root->rch);
	post.push_back(root->data);
}
int ans1=0;
void right2left(node* root,int depth){
	if(root==NULL)
		return;
	if(depth>ans1)
		ans1=depth;
	right2left(root->lch,depth+1);
	right2left(root->rch,depth+1);
}
int ans2=0;
void rightup2leftdown(node* root,int right){
	if(root==NULL)
		return;
	if(right>ans2)
		ans2=right;
	rightup2leftdown(root->lch,right);
	rightup2leftdown(root->rch,right+1);
}
int leftmin=0,rightmax=0;
void up2down(node* root,int balance){
	if(root==NULL)
		return;
	if(balance>rightmax)
		rightmax=balance;
	if(balance<leftmin)
		leftmin=balance;
	up2down(root->lch,balance-1);
	up2down(root->rch,balance+1);
}

int main(){
	freopen("G:\\PATdata\\codeup_27736_shangdishijiao.txt","r",stdin);
	cin>>n;
	int x;
	for(int i=0;i<n;i++){
		cin>>x;
		layer.push_back(x);
	}
	for(int i=0;i<n;i++){
		cin>>in[i];
	}
	node* root=create(layer,0,n-1);
	preod(root);
	postod(root);
	for(int i=0;i<n;i++){
		cout<<pre[i];
		if(i<n-1)
			cout<<" ";
	}
	cout<<endl;
	for(int i=0;i<n;i++){
		cout<<post[i];
		if(i<n-1)
			cout<<" ";
	}
	cout<<endl;
	
	right2left(root,1);
	rightup2leftdown(root,1);
	up2down(root,0);
	cout<<ans1<<endl<<ans2<<endl<<rightmax-leftmin+1<<endl;

	return 0;
}