#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
const int maxn=100010;
int a[maxn];
int n,p;
int bin(int l,int r,int key){//二分查找key的下标
	int mid;
	while(l<=r){
		mid=(l+r)/2;
		if(a[mid]==key)
			return mid;
		else if(a[mid]>key)
			r=mid-1;
		else
			l=mid+1;
	}
	return -1;
}
int main(){
	freopen("G://PATdata//A1048.txt","r",stdin);
	scanf("%d%d", &n, &p);
    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    sort(a, a + n);
	int i=0;
	for(i=0;i<n;i++){
		int pos=bin(0,n-1,p-a[i]);//二分查找p-a[i]的下标
		if(pos!=-1 && i!=pos){    ///////////
			printf("%d %d\n",a[i],a[pos]);
			break;
		}
	}
	if(i==n)////////////////////
		printf("No Solution\n");
	return 0;
}