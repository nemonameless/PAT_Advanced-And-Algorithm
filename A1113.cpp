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
const int maxn=100010;
typedef long long LL;
LL d[maxn];
int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&d[i]);
	}
	sort(d,d+n);
	int ans1=0,ans2=0;
	if(n%2==0){
		for(int i=0;i<n/2;i++){
			ans1+=d[i];
		}
		for(int i=n/2;i<n;i++){
			ans2+=d[i];
		}
		printf("0 %d\n",ans2-ans1);
	}else{
		int tmp1=0,tmp2=0;
		for(int i=0;i<n/2;i++){
			ans1+=d[i];
		}
		for(int i=n/2;i<n;i++){
			ans2+=d[i];
		}

		for(int i=0;i<n/2+1;i++){
			tmp1+=d[i];
		}
		for(int i=n/2+1;i<n;i++){
			tmp2+=d[i];
		}

		printf("1 %d\n",max(ans2-ans1,tmp2-tmp1));
	}

	return 0;
}