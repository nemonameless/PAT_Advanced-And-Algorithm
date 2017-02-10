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
const int maxn=10010;
int a[maxn],b[maxn];
int dp[maxn][maxn];
int main(){
	//freopen("G:\\PATdata\\A1045.txt","r",stdin);
	int m,n,k;
	scanf("%d%d",&m,&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	scanf("%d",&k);
	for(int i=1;i<=k;i++){
		scanf("%d",&b[i]);
	}
	for(int i=0;i<=n;i++){
		dp[i][0]=0;
	}
	for(int i=0;i<=k;i++){
		dp[0][i]=0;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=k;j++){
			int MAX=max(dp[i-1][j-1],max(dp[i-1][j],dp[i][j-1]));
			if(a[i]==b[j])
				dp[i][j]=MAX+1;
			else
				dp[i][j]=MAX;
		}
	}
	printf("%d\n",dp[n][k]);
	return 0;
}