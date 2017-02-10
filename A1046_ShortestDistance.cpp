#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=1e5+1;
int dis[maxn]={0};
int main(){
	int n,m,tmp;
	int left,right,sum=0;
	freopen("G:\\PATdata\\A1046.txt","r",stdin);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&tmp);
		sum+=tmp;
		dis[i]=sum;   //²»¿ÉÐ´³Édis[i]+=tmp
	}
	scanf("%d",&m);
	for(int i=0;i<m;i++){
		scanf("%d %d",&left,&right);
		if(left>right)
			swap(left,right);
		int t=dis[right-1]-dis[left-1];
		printf("%d\n",min(t,sum-t));
	}


	return 0;
}