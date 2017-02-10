///paste.ubuntu.com/15327756/  ¾²Ì¬Ê÷Ð´·¨
#include<cstdio>
#include<queue>
#include<cstring>
#include<vector>
using namespace std;
const int maxn=31;
struct node{
	int data;
	node *lch,*rch;
};
void insert(node* &root,int data){
	if(root==NULL){
		root=new node;
		root->data=data;
		root->lch=NULL;
		root->rch=NULL;
		return;
	}
	if(data<root->data)
		insert(root->lch,data);
	else
		insert(root->rch,data);
}
void postod(node* root,vector<int> &vi){
	if(root==NULL)
		return;
	postod(root->lch,vi);
	postod(root->rch,vi);
	vi.push_back(root->data);
}
void inod(node* root,vector<int> &vi){
	if(root==NULL)
		return;
	inod(root->lch,vi);
	vi.push_back(root->data);
	inod(root->rch,vi);
}
int num=0,n;
void BFS(node* root){
    queue<node*> q;
    q.push(root);
    num=0;
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
vector<int> post1,post2,bfs1,bfs2,in1,in2;
int main(){
	int data;
	node* root1=NULL,*root2=NULL;

	freopen("G:\\PATdata\\codeup27731_bst.txt","r",stdin);
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&data);
		insert(root1,data);
	}
	postod(root1,post1);
	inod(root1,in1);
	for(int i=0;i<n;i++){
		scanf("%d",&data);
		insert(root2,data);
	}
	postod(root2,post2);	
	inod(root2,in2);
	if(post1==post2 && in1==in2){
		printf("YES\n");
	}else
		printf("NO\n");
	for(int i=0;i<n;i++){
        printf("%d",post1[i]);
            if(i<n-1)
                printf(" ");
    }
	printf("\n");
	BFS(root1);//////////////////////////////
	printf("\n");

	return 0;
}


