#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	int n,m,c[100001]={},p[100001]={};
	freopen("G:\\PATdata\\A1037.txt","r",stdin);
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&c[i]);
	}
	sort(c,c+n,cmp);
	scanf("%d",&m);
	for(int i=0;i<m;i++){
		scanf("%d",&p[i]);
	}
	sort(p,p+m,cmp);
	int ans=0;
	for(int i=0;i<min(n,m) && c[i]>0 && p[i]>0;i++){
		ans+=c[i]*p[i];
	}
	for(int i=n-1,j=m-1;i>=0 && j>=0 && c[i]<0 && p[j]<0;i--,j--){
		ans+=c[i]*p[j];
	}
	printf("%d\n",ans);

	return 0;
}
