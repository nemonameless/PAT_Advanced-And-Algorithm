#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct Mcake{
	double sell,store,price;
}mcake[1001];
bool cmp(Mcake a,Mcake b){
	return a.price>b.price;
}
int main(){
	int n,demand;
	scanf("%d %d",&n,&demand);
	for(int i=0;i<n;i++){
		scanf("%lf",&mcake[i].store);
	}
	for(int i=0;i<n;i++){
		scanf("%lf",&mcake[i].sell);
		mcake[i].price = mcake[i].sell*1.0 / mcake[i].store;
		//printf("%f\n",mcake[i].price);
	}
	sort(mcake,mcake+n,cmp);
	double all=0;

	for(int i=0;i<n;i++){
		if(mcake[i].store < demand){///////////storeºÍsellÎð¸ã»ì
			all+=mcake[i].sell;
			demand= demand - mcake[i].store;
			//printf("%f\n",demand);
		}else{
			all+= demand*mcake[i].price;
			break;
		}
	}
	printf("%.2f",all);

	return 0;
}
