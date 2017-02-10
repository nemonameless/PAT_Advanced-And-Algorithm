#include<cstdio>
#include<cstring>
#include<stack>
#include<algorithm>
using namespace std;
const int maxn=50;
struct node{
	int data;
	node* lch,*rch;
};
int pre[maxn],in[maxn],post[maxn];
int n,num=0;
void postod(node* root){
	if(root==NULL)
		return;
	postod(root->lch);
	postod(root->rch);
	printf("%d",root->data);
	num++;
	if(num<n)
		printf(" ");
}
node* create(int prel,int prer,int inl,int inr){
	if(prel>prer)
		return NULL;
	node* root=new node;
	root->data=pre[prel];
	int k;
	for(k=inl;k<inr;k++){
		if(in[k]==pre[prel])
			break;
	}
	int numleft=k-inl;
	root->lch=create(prel+1,prel+numleft,inl,k-1);
	root->rch=create(prel+numleft+1,prer,k+1,inr);
	return root;
}
int main(){
	char str[5];
	int prenum=0,innum=0,x;
	stack<int> st;

	scanf("%d",&n);
	for(int i=0;i<2*n;i++){
		scanf("%s",str);
		if(strcmp(str,"Push")==0){
			scanf("%d",&x);
			st.push(x);
			pre[prenum++]=x;
		}else{
			in[innum++]=st.top();//////////
			st.pop();
		}
	}
	node* root=create(0,n-1,0,n-1);
	postod(root);
	return 0;
}

