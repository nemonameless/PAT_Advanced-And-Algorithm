#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
typedef long long LL;
int main(){
	LL n;
//	freopen("G:\\PATdata\\A1096.txt","r",stdin);
	scanf("%lld",&n);
	LL s=(LL)sqrt(1.0*n);
	LL ansi=0,anslen=0;
	for(LL i=2;i<=s;i++){
		LL tmp=1,j=i;
		while(1){
			tmp*=j;
			if(n%tmp)/////////////////////////////
				break;
			if(j-i+1>anslen){
				ansi=i;
				anslen=j-i+1;
			}
			j++;
		}
	}
	if(anslen==0){
		printf("1\n%lld\n",n);
	}else{
		printf("%lld\n",anslen);
		for(LL i=0;i<anslen;i++){
			printf("%lld",ansi+i);
			if(i<anslen-1)
				printf("*");
		}
	}
	return 0;
}