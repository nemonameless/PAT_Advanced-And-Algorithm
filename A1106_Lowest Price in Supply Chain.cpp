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
int mindepth=maxn;/////////////////////////////±ØÐë×ã¹»´ó
int num=0;
void dfs(int index,int depth){
	if(child[index].size()==0){
		if(depth<mindepth){
			mindepth=depth;
			num=0;/////////////////
		}
		if(depth==mindepth){
			num++;
		}
		return;
	}
	for(int i=0;i<child[index].size();i++){
		dfs(child[index][i],depth+1);
	}
}
bool notroot[maxn]={false};
int main(){
	int n,father,root;
	double p,r;	
	//freopen("G:\\PATdata\\A1106.txt","r",stdin);
	cin>>n>>p>>r;
	r/=100;
	int k,son;
	for(int i=0;i<n;i++){
		cin>>k;
		if(k){
			for(int j=0;j<k;j++){
				cin>>son;
				child[i].push_back(son);////////////////////////////////////
				notroot[son]=true;
			}
		}
		
	}
	for(int i=0;i<n;i++){
		if(notroot[i]==false){
			root=i;
			break;
		}
	}
	dfs(root,0);
	printf("%.4f %d\n",p*pow((1+r),mindepth),num);

	return 0;
}
