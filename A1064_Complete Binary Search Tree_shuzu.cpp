#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
const int maxn=1001;
int a[maxn],cbt[maxn],in[maxn],n,num=0;
void inod(int root){
	if(root>n)
		return;
	inod(root*2);
	cbt[root]=a[num++];
	inod(root*2+1);
}

int main(){
	freopen("G:\\PATdata\\A1064.txt","r",stdin);
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	sort(a,a+n);
	inod(1);
	for(int i=1;i<=n;i++){
		printf("%d",cbt[i]);
		if(i<n)
			printf(" ");
	}
	

	return 0;
}
