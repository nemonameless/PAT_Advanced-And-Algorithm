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
const int maxn=1010;
bool inq[1300][130][61]={false};
int maze[1300][130][61]={};
struct node{
	int x,y,z;
}nd;
int X[6]={0,0,0,0,1,-1};
int Y[6]={0,0,1,-1,0,0};
int Z[6]={1,-1,0,0,0,0};
int n,m,l,t;
bool test(int x,int y,int z){
	if(x<0 || x>=n||y<0||y>=m||z>=l||z<0||inq[x][y][z]==true || maze[x][y][z]==0)
		return 0;
	return 1;
}
int bfs(int x,int y,int z){
	queue<node> q;
	nd.x=x;nd.y=y;nd.z=z;
	q.push(nd);
	int tot=0;
	inq[x][y][z]=true;
	while(!q.empty()){
		node top=q.front();
		q.pop();
		tot++;
		for(int i=0;i<6;i++){
			int newx=top.x+X[i];
			int newy=top.y+Y[i];
			int newz=top.z+Z[i];
			if(test(newx,newy,newz)){
				nd.x=newx;
				nd.y=newy;
				nd.z=newz;
				q.push(nd);
				inq[newx][newy][newz]=true;//////////
			}
		}
	}

	if(tot>=t)
		return tot;
	else
		return 0;
}

int main(){
	freopen("G:\\PATdata\\A1091.txt","r",stdin);
	cin>>n>>m>>l>>t;
	for(int z=0;z<l;z++)
		for(int x=0;x<n;x++)
			for(int y=0;y<m;y++)
				cin>>maze[x][y][z];
	int ans=0;
	for(int z=0;z<l;z++)
		for(int x=0;x<n;x++)
			for(int y=0;y<m;y++)
				if(maze[x][y][z]==1 && inq[x][y][z]==false)///////////
					ans+=bfs(x,y,z);
	cout<<ans<<endl;
	return 0;
}