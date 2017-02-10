#include<cstdio>
#include<cstring>
#include<iostream>
//#include<algorithm>
using namespace std;
const int maxn=1e5+1;
int sum[maxn];
int n,p,nearp=1e8+1;
int upper_bound(int l,int r,int x){
	int left=l,right=r,mid;
	while(left < right){
		mid=(left+right)/2;
		if(sum[mid]<=x)
			left=mid+1;
		else if(sum[mid]>x)
			right=mid;
	}
	return left;
}
int main(){
	//freopen("G://PATdata//A1044.txt","r",stdin);
	scanf("%d%d", &n, &p);
    for(int i = 1; i <=n; i++) {
        scanf("%d", &sum[i]);
		sum[i]+=sum[i-1];
    }
   for(int i=1;i<=n;i++){
	   int j=upper_bound(i,n+1,sum[i-1]+p);
	   if(sum[j-1]-sum[i-1]==p){
		   nearp=p;
			break;
	   }else if(j<=n && sum[j]-sum[i-1]<nearp){
			nearp=sum[j]-sum[i-1];
	   }
	}
   for(int i=1;i<=n;i++){
	   int j=upper_bound(i,n+1,sum[i-1]+nearp);//////
	   if(sum[j-1]-sum[i-1]==nearp){//////////////
		  printf("%d-%d\n",i,j-1);
	}
   }
	
	return 0;
}