#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
using namespace std;
const int maxn=100001;
const int INF=0x3fffffff;
int a[maxn]={},leftmax[maxn],rightmin[maxn];
int ans[maxn];//¼ÇÂ¼Ö÷Ôª;
int main(){
	int n;
	freopen("G://PATdata//A1101.txt","r",stdin);
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	int num=0,k;
	leftmax[0]=0;
	for(int i=1;i<n;i++){
		leftmax[i]=max(leftmax[i-1],a[i-1]);////
	}
	rightmin[n-1]=INF;
	for(int i=n-2;i>=0;i--){
		rightmin[i]=min(rightmin[i+1],a[i+1]);////
	}
	for(int i=0;i<n;i++){
		if(a[i]>leftmax[i] && a[i]<rightmin[i])
			ans[num++]=a[i];
	}
	printf("%d\n",num);
	for(int i=0;i<num;i++){
		if(i)
			printf(" ");
		printf("%d",ans[i]);
	}
	printf("\n");
	return 0;
}