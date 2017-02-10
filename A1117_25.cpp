//14fen
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
#include<cctype>
#include<queue>
#include<stack>
#include<map>
#include<cmath>
using namespace std;
const int mx= 1e5+1;
int n;
int dis[mx];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("G:\\PATdata\\A1117.txt","r",stdin);
	scanf("%d",&n);
	for(int i=0;i<n;i++){		
		scanf("%d",&dis[i]);
	}
	sort(dis,dis+n,cmp);
	int num=0;
	for(int i=0;i<n;i++){
		if(dis[i]>i+1){//////////////>i+1是关键,即求满足a[i] > i+1的最大值
			num++;
		}	
	}
	printf("%d\n",num);

	return 0;
}