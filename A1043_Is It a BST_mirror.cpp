#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
const int maxn=1001;
struct node{
	int data;
	node* lch,*rch;
};
vector<int> origin,pre,prem,post,postm;
void insert(node* &root,int data){
	if(root==NULL){
		root=new node;
		root->data=data;
		root->lch=root->rch=NULL;
		return;
	}
	if(data<root->data)
		insert(root->lch,data);
	if(data>=root->data)
		insert(root->rch,data);
}
void preod(node* root,vector<int>& vi){
	if(root==NULL)
		return;
	vi.push_back(root->data);
	preod(root->lch,vi);
	preod(root->rch,vi);
}
void preodmm(node* root,vector<int>& vi){
	if(root==NULL)
		return;
	vi.push_back(root->data);
	preodmm(root->rch,vi);
	preodmm(root->lch,vi);
}
void postod(node* root,vector<int>& vi){
	if(root==NULL)
		return;
	
	postod(root->lch,vi);
	postod(root->rch,vi);
	vi.push_back(root->data);
}
void postodmm(node* root,vector<int>& vi){
	if(root==NULL)
		return;
	
	postodmm(root->rch,vi);
	postodmm(root->lch,vi);
	vi.push_back(root->data);
}

int main(){
	freopen("G:\\PATdata\\A1043.txt","r",stdin);
	int n,data;
	scanf("%d",&n);
	node* root=NULL;
	for(int i=0;i<n;i++){
		scanf("%d",&data);
		origin.push_back(data);
		insert(root,data);
	}
	preod(root,pre);
	preodmm(root,prem);
	postod(root,post);
	postodmm(root,postm);
	if(origin==pre){
		printf("YES\n");
		for(int i=0;i<post.size();i++){
			printf("%d",post[i]);
			if(i<post.size()-1)
				printf(" ");
		}
	}else if(origin==prem){
		printf("YES\n");
		for(int i=0;i<postm.size();i++){
			printf("%d",postm[i]);
			if(i<postm.size()-1)
				printf(" ");
		}
	}else
		printf("NO\n");

	return 0;
}

