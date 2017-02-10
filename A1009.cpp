#include<cstdio>
using namespace std;
struct Poly{
	int exp;
	double cof;
}poly[1001];
int main(){
	int k,n,cnt=0;
	double ans[2001]={0};
	//freopen("G:\\PATdata\\A1009.txt","r",stdin);
	scanf("%d",&k);
	for(int i=0;i<k;i++){
		scanf("%d %lf",&poly[i].exp,&poly[i].cof);
	}
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		int exp;
		double cof;
		scanf("%d %lf",&exp,&cof);
		for(int j=0;j<k;j++){
			ans[exp+poly[j].exp]+=cof*poly[j].cof;//////////////////
		}
	}
	for(int i=0;i<2001;i++)
	{
		if(ans[i]!=0.0)
			cnt++;
	}
	printf("%d",cnt);                ////////
	for(int i=2000;i>=0;i--){
		if(ans[i]!=0.0)
			printf(" %d %.1f",i,ans[i]);/////////////
	}


	return 0;
}

