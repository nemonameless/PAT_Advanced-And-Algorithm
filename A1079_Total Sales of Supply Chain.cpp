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
struct Node{
	vector<int> child;
	int weight;
}nd[maxn];
int mindepth=maxn;/////////////////////////////必须足够大
int num=0;
double ans=0;////////////////////////////////////////////////////double,定义int会出错
double p,r;
void dfs(int index,int depth){
	if(nd[index].child.size()==0){
		int w=nd[index].weight;
		ans+=p*w*pow((1+r),depth);	
		return;
	}
	for(int i=0;i<nd[index].child.size();i++){
		dfs(nd[index].child[i],depth+1);
	}
}
int main(){
	int n;
	freopen("G:\\PATdata\\A1079.txt","r",stdin);
	scanf("%d %lf %lf",&n,&p,&r);
	r/=100;
	int k,son;
	for(int i=0;i<n;i++){
		scanf("%d",&k);
		if(k!=0){
			for(int j=0;j<k;j++){
				scanf("%d",&son);
				nd[i].child.push_back(son);
			}
		}else{
			scanf("%d",&nd[i].weight);
		}
		
	}
	dfs(0,0);
	printf("%.1f\n",ans);

	return 0;
}
