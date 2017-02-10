#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
const int maxn=100010;
int a[maxn];
int n,p;
void twopointers(int n,int p){
	int i=0,j=n-1;
	while(i<j){
		if(a[i]+a[j]==p)
			break;
		else if(a[i]+a[j]<p)
			i++;
		else
			j--;
	}
	if(i<j)
		printf("%d %d\n",a[i],a[j]);
	else
		 printf("No Solution\n");
}

int main(){
	freopen("G://PATdata//A1048.txt","r",stdin);
	scanf("%d%d", &n, &p);
    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    sort(a, a + n);
	twopointers(n,p);
	return 0;
}