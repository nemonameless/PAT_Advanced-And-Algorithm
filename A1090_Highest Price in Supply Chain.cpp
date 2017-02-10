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
const int maxn=100001;
vector<int> child[maxn];
int maxdepth=0;
int num=0;
void dfs(int index,int depth){
	if(child[index].size()==0){
		if(depth>maxdepth){
			maxdepth=depth;
			num=0;///////////////////////////// 
		}
		if(depth==maxdepth){
			num++;
		}
		return;
	}
	for(int i=0;i<child[index].size();i++){
		dfs(child[index][i],depth+1);
	}
}
int main(){
	int n,father,root;
	double p,r;	
	//freopen("G:\\PATdata\\A1090.txt","r",stdin);
	cin>>n>>p>>r;
	r/=100;
	for(int i=0;i<n;i++){
		cin>>father;
		if(father!=-1){
			child[father].push_back(i);
		}else
			root=i;
	}
	dfs(root,0);
	printf("%.2f %d\n",p*pow((1+r),maxdepth),num);

	return 0;
}
