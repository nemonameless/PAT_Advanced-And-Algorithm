#include<cstdio>
#include<cstring>
#include<stack>
#include<queue>
#include<algorithm>
using namespace std;
const int maxn=110;
struct Node{
	int lch,rch,data;
}node[maxn];
int n,num=0;
void BFS(int root){
	queue<int> q;
	q.push(root);
	while(!q.empty()){
		int now=q.front();
		q.pop();
		printf("%d",node[now].data);
		num++;
		if(num<n)
			printf(" ");
		if(node[now].lch!=-1)
			q.push(node[now].lch);
		if(node[now].rch!=-1)
			q.push(node[now].rch);
	}
}
int in[maxn];
void inod(int root){
	if(root==-1)
		return;
	inod(node[root].lch);
	node[root].data=in[num++];
	inod(node[root].rch);
}

int main(){
	freopen("G:\\PATdata\\A1099.txt","r",stdin);
	scanf("%d",&n);
	int lch,rch;
	for(int i=0;i<n;i++){
		scanf("%d %d",&node[i].lch,&node[i].rch);
	}
	
	for(int i=0;i<n;i++){
		scanf("%d",&in[i]);
	}
	sort(in,in+n);
	inod(0);
	num=0;
	BFS(0);
	return 0;
}

