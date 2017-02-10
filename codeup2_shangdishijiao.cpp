#include<cstdio>
#include<cstring>
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
const int maxn=31;
vector<int> pre,post,layer;
int in[maxn];
struct node{
	int data,lch,rch;
}nd[maxn];
int num=0;
int newnode(int x){
	nd[num].data=x;
	nd[num].lch=nd[num].rch=-1;
	return num++;
}
int create(vector<int> layer,int inl,int inr){
	if(layer.size()==0)
		return -1;
	int root=newnode(layer[0]);
	int k;
	for(k=inl;k<=inr;k++){
		if(in[k]==layer[0])
			break;
	}
	vector<int> layerleft,layerright;
	for(int i=1;i<layer.size();i++){
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
	nd[root].lch=create(layerleft,inl,k-1);
	nd[root].rch=create(layerright,k+1,inr);
	return root;
}
void preod(int root){
	if(root==-1)
		return;
	pre.push_back(nd[root].data);
	preod(nd[root].lch);
	preod(nd[root].rch);
}
void postod(int root){
	if(root==-1)
		return;	
	postod(nd[root].lch);
	postod(nd[root].rch);
	post.push_back(nd[root].data);
}
int ans1=0;
void right2leftDFS(int root,int depth){
	if(root==-1)
		return;
	if(depth>ans1)
		ans1=depth;
	right2leftDFS(nd[root].lch,depth+1);
	right2leftDFS(nd[root].rch,depth+1);
}
int ans2=0;
void rightup2leftdownDFS(int root,int right){
	if(root==-1)
		return;
	if(right>ans2)
		ans2=right;
	rightup2leftdownDFS(nd[root].lch,right);
	rightup2leftdownDFS(nd[root].rch,right+1);
}
int leftmin=0,rightmax=0;
void up2downDFS(int root,int balance){
	if(root==-1)
		return;
	if(balance>rightmax)
		rightmax=balance;
	if(balance<leftmin)
		leftmin=balance;
	up2downDFS(nd[root].lch,balance-1);
	up2downDFS(nd[root].rch,balance+1);
}

int main(){
	int n,tmp;
	freopen("G:\\PATdata\\codeup_27736_shangdishijiao.txt","r",stdin);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>tmp;
		layer.push_back(tmp);
	}
	for(int i=0;i<n;i++){
		cin>>in[i];
	}
	int root=create(layer,0,n-1);
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
	right2leftDFS(root,1);
	rightup2leftdownDFS(root,1);
	up2downDFS(root,0);
	cout<<ans1<<endl;
	cout<<ans2<<endl;
	cout<<rightmax-leftmin+1<<endl;


	return 0;
}
