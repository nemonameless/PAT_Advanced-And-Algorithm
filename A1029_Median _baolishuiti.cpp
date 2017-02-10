#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
const int maxn=1000001;
int a[maxn*2];
int main(){
	int n,m;
	//freopen("G://PATdata//A1029.txt","r",stdin);
	scanf("%d", &n);
    for(int i = 0; i <n; i++) {
        scanf("%d", &a[i]);
    }
	scanf("%d", &m);
   for(int i=n;i<n+m;i++){
	    scanf("%d", &a[i]);
	}
   sort(a,a+n+m);
   if((m+n)%2)
		printf("%d\n",a[(m+n)/2]);
   else
	   printf("%d\n",a[(m+n)/2-1]);
	
	return 0;
}