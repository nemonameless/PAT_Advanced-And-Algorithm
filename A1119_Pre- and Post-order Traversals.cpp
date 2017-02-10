//////http:
//www.cnblogs.com/demian/p/6103285.html前序从前向后找，后序从后向前找，观察正反样例可知，前后序树不唯一在于单一子树是否为左右子树。

 //   判断特征：通过查找后序序列中最后一个结点的前一个在先序中的位置，来确定是否可以划分左右孩子，如果不能， 就将其划分为右孩子（或左孩子），递归建树。


#include<cstdio>
using namespace std;
int n;
const int maxn=31;
int pre[maxn],post[maxn];
int flag=1;
struct node{
	int data;
	node *lch,*rch;
};
node *create(int prel,int prer,int postl,int postr){
	if(prel>prer)
		return NULL;
	node* root=new node;
	root->data=pre[prel];

	root->lch=NULL;///////////不能不写
	root->rch=NULL;///////////////
	
	if (prel == prer)  
        return root;  
	int k=0;
	for(k=prel+1;k<=prer;k++){
		if(pre[k]==post[postr-1])
			break;
	}
	int numleft=k-prel;
	if(numleft>1){
		root->lch=create(prel+1,k-1,  postl,          postl+numleft-2);//////////
		root->rch=create(k     ,prer, postl+numleft-1,postr-1);///////////
	}else{
		flag=0;
		root->rch=create(k,prer,postl+numleft-1,postr-1);
	}
	return root;
}
int num=0;
void inod(node *root){
	if(root==NULL)
		return;

	inod(root->lch);
	printf("%d",root->data);
	num++;
	if(num<n)
		printf(" ");
	inod(root->rch);
}
int main(){
	freopen("G:\\PATdata\\A1119.txt","r",stdin);
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&pre[i]);
	}
	for(int i=0;i<n;i++){
		scanf("%d",&post[i]);
	}
	node* root=create(0,n-1,0,n-1);
	if(flag)
		printf("Yes\n");
	else
		printf("No\n");
	inod(root);
	printf("\n");//////////////////////////////不加这句没分！ 
	return 0;
}
