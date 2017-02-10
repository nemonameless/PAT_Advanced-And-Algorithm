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
const int maxn=101;
char maze[maxn][maxn];
bool inq[maxn][maxn]={false};
int n,m;
int X[4]={0,0,1,-1};
int Y[4]={1,-1,0,0};
struct node{
	int x,y,step;
}S,T,Node;
bool judge(int x,int y){
	if(x>=n ||x<0 || y>=m || y<0)
		return false;
	if(maze[x][y]=='*' || inq[x][y]==true)
		return false;
	return true;
}
int ans=0;
void BFS()
{
	queue<node> Q;
	Q.push(S);
	while(!Q.empty())
	{
		node top = Q.front();
		Q.pop();
		if(top.x==T.x && top.y==T.y)
			ans = top.step;
		
		for(int i=0;i<4;i++)
		{
			int newx=top.x+X[i];
			int newy=top.y+Y[i];
			if(judge(newx,newy))
			{
				Node.x=newx;Node.y=newy;
				Node.step=top.step+1;
				Q.push(Node);
				printf("[%d,%d] ",Node.x,Node.y);//BFS特点，所有点都会打印，无法单独打印正确路线 
				inq[newx][newy]=true;
				
			}
		}
			printf("\n");
	}
}
int main(){
	freopen("G:\\PATdata\\BFSmigong.txt","r",stdin);
	scanf("%d %d",&n,&m);//////////////////////////////////////////
	for(int i=0;i<n;i++){
		getchar();/////////
		for(int j=0;j<m;j++){
			maze[i][j]=getchar();
		}
		maze[i][m+1]='\0';  
	}
	scanf("%d %d %d %d",&S.x,&S.y,&T.x,&T.y);
	S.step=0;
	//int ans=0;
	BFS();
	
	printf("%d\n",ans);
	return 0;
}
