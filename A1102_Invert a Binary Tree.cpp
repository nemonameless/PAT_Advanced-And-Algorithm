#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;
const int maxn=110;
struct Node{
	int lch,rch;
}node[maxn];
bool notroot[maxn]={false};
int n;
void postod(int root){
	if(root==-1)
		return;
	postod(node[root].lch);
	postod(node[root].rch);
	swap(node[root].lch,node[root].rch);
}
int num=0;
void print(int id){
	
	printf("%d",id);
	num++;
	if(num<n)
		printf(" ");
	else
		printf("\n");

}
void inod(int root){
	if(root==-1)
		return;
	inod(node[root].lch);
	print(root);
	inod(node[root].rch);
}
int findroot(){
	int i;
	for(i=0;i<n;i++){
		if(notroot[i]==false)
			break;
	}
	return i;
}
int str2num(char c){
	if(c=='-')
		return -1;
	else{
		notroot[c-'0']=true;
		return c-'0';
	}
}
void BFS(int root){
	queue<int> q;
	q.push(root);
	while(!q.empty()){
		int now=q.front();
		q.pop();
		print(now);
		if(node[now].lch!=-1)
			q.push(node[now].lch);
		if(node[now].rch!=-1)
			q.push(node[now].rch);
	}
}
int main(){
	freopen("G:\\PATdata\\A1102.txt","r",stdin);
	scanf("%d",&n);
	char lch,rch;
	for(int i=0;i<n;i++){
		scanf("%*c%c %c",&lch,&rch);//////////
		node[i].lch=str2num(lch);
		node[i].rch=str2num(rch);
	}
	int root=findroot();
	postod(root);
	BFS(root);
	num=0;
	inod(root);
	return 0;
}




