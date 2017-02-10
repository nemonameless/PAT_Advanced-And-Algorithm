#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int INF=1e9;
struct Station{
	double dis,price;
}st[501];
bool cmp(Station a,Station b){
	return a.dis<b.dis;
}
int main(){
	double Cmax,D,Davg;
	int n;
	freopen("G:\\PATdata\\A1033.txt","r",stdin);
	scanf("%lf%lf%lf%d",&Cmax,&D,&Davg,&n);
	for(int i=0;i<n;i++){
		scanf("%lf%lf",&st[i].price,&st[i].dis);
	}
	st[n].price=0.00;
	st[n].dis=D;
	sort(st,st+n,cmp);///////////////
	if(st[0].dis!=0)
		printf("The maximum travel distance = 0.00\n");
	else{
		int now=0;
		double MAX=Cmax*Davg;//ÂúÓÍÐÐÊ»¾àÀë
		double ans=0,nowTank=0;//
		while(now<n){
			int k=-1;
			double priceMin=INF;
			for(int i=now+1;i<=n && st[i].dis-st[now].dis <= MAX; i++){
				if(st[i].price< priceMin){
					priceMin=st[i].price;
					k=i;
					if(priceMin < st[now].price)
						break;
				}
			}
			if(k==-1)
				break;
			double need=(st[k].dis - st[now].dis)/Davg;
			if(priceMin<st[now].price){
				if(nowTank<need){
					ans+=(need-nowTank)*st[now].price;
					nowTank=0;////////////
				}else{
					nowTank-=need;
				}
			}else{
				ans+=(Cmax-nowTank)*st[now].price;
				nowTank=Cmax-need;
			}
			now=k;
		}
		if(now==n)
			printf("%.2f\n",ans);
		else
			printf("The maximum travel distance = %.2f\n",st[now].dis+MAX);
	}
	return 0;
}


