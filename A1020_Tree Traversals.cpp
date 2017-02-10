#include<cstdio>
#include<queue>
#include<algorithm>
using namespace std;
const int maxn=50;
struct node{
	int data;
	node* lch,*rch;
};
int post[maxn],in[maxn],pre[maxn];
node* create(int inl,int inr,int postl,int postr){
	if(postl>postr)
		return NULL;
	node* root=new node;
	root->data=post[postr];
	int k;
	for(k=inl;k<=inr;k++){
		if(in[k]==post[postr])
			break;
	}
	int numleft=k-inl;
	root->lch=create(inl,k-1,postl,postl+numleft-1);
	root->rch=create(k+1,inr,postl+numleft,postr-1);
	return root;
}
int num=0,n;
void BFS(node* root){
	queue<node*> q;
	q.push(root);

	while(!q.empty()){
		node* now=q.front();
		q.pop();
		printf("%d",now->data);
		num++;
		if(num<n)
			printf(" ");
		if(now->lch!=NULL)
			q.push(now->lch);
		if(now->rch!=NULL)
			q.push(now->rch);
	}
}
int main(){
	freopen("G:\\PATdata\\A1020.txt","r",stdin);
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&post[i]);
	}
	for(int i=0;i<n;i++){
		scanf("%d",&in[i]);
	}
	node* root;
	root=create(0,n-1,0,n-1);
	BFS(root);

	return 0;
}