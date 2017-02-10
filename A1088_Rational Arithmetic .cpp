#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<cctype>
#include<algorithm>
#include<cmath>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<stack>
using namespace std;
const int maxn=1010;
typedef long long ll;
struct Fract{
	ll zi,mu;
};
ll gcd(ll a,ll b){
	return b==0?a:gcd(b,a%b);/////////////////////
}
Fract yuefen(Fract result){
	if(result.zi<0){
		result.zi=-result.zi;
		result.mu=-result.mu;
	}
	if(result.zi==0){
		result.mu=1;
	}else{
		int d=gcd(abs(result.zi),abs(result.mu));
		result.zi/=d;
		result.mu/=d;
	}
	return result;
}
Fract add(Fract a,Fract b){
	Fract result;
	result.zi=a.zi*b.mu+a.mu*b.zi;
	result.mu=a.mu*b.mu;
	return yuefen(result);
}
Fract jian(Fract a,Fract b){
	Fract result;
	result.zi=a.zi*b.mu-a.mu*b.zi;
	result.mu=a.mu*b.mu;
	return yuefen(result);
}
Fract mult(Fract a,Fract b){
	Fract result;
	result.zi=a.zi*b.zi;
	result.mu=a.mu*b.mu;
	return yuefen(result);
}
Fract chu(Fract a,Fract b){
	Fract result;
		result.zi=a.zi*b.mu;
		result.mu=a.mu*b.zi;
		return yuefen(result);
}
void show(Fract r){
	r=yuefen(r);
	bool fu=false;
	if(r.zi==0){
		printf("0");
		return;
	}else if(r.zi*r.mu<0){
		printf("(-");
		fu=true;
	}
	r.zi=abs(r.zi);
	r.mu=abs(r.mu);
	if(r.zi>r.mu && r.zi%r.mu!=0 ){
		printf("%lld %lld/%lld",r.zi/r.mu,r.zi%r.mu,r.mu);
	}else if(r.zi>r.mu && r.zi%r.mu==0){
		printf("%lld",r.zi/r.mu);
	}else if(r.zi==r.mu){
		printf("1");
	}else{
		printf("%lld/%lld",r.zi,r.mu);
	}
	if(fu)
		printf(")");
}
int main(){
	Fract a,b,he,cha,ji;
	//freopen("G:\\PATdata\\A1088.txt","r",stdin);
	while(scanf("%lld/%lld %lld/%lld",&a.zi,&a.mu,&b.zi,&b.mu)!=EOF){
	//	a=yuefen(a),b=yuefen(b);
		show(a);
		printf(" + ");
		show(b);
		printf(" = ");
		he=add(a,b);
		show(he);
		printf("\n");

		show(a);
		printf(" - ");
		show(b);
		printf(" = ");
		cha=jian(a,b);
		show(cha);
		printf("\n");

		show(a);
		printf(" * ");
		show(b);
		printf(" = ");
		ji=mult(a,b);
		show(ji);
		printf("\n");

		show(a);
		printf(" / ");
		show(b);
		printf(" = ");
		//chu(a,b);
			Fract shang;
			if(b.mu!=0 && b.zi!=0){
				shang=chu(a,b);
				show(shang);
			}else{
				printf("Inf");
			}

		printf("\n");
	}
	return 0;
}
