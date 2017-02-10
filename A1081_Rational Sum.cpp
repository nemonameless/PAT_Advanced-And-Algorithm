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
	return b==0?a:gcd(b,a%b);//////////////////////////
}
Fract yuefen(Fract a){
	if(a.zi<0){
		a.zi=-a.zi;
		a.mu=-a.mu;///////////////////////////////
	}else if(a.zi==0){
		a.mu=1;
	}else{
		ll d=gcd(abs(a.zi),abs(a.mu));
		a.zi/=d;
		a.mu/=d;
	}
	return a;
}
Fract add(Fract a,Fract b){
	Fract result;
	result.zi=a.zi*b.mu+a.mu*b.zi;
	result.mu=a.mu*b.mu;
	return yuefen(result);
}
void show(Fract r){
	r=yuefen(r);
	if(r.zi<0){
		printf("-");
		r.zi=-r.zi;
	}else if(r.mu==1)
		printf("%lld\n",r.zi);//////////////////////////////
	else if(r.zi>r.mu)
		printf("%lld %lld/%lld\n",r.zi/r.mu,r.zi%r.mu,r.mu);
	else if(r.zi<r.mu)
		printf("%lld/%lld\n",r.zi,r.mu);
}

int main(){
	Fract temp,ans;
	int n;

	//freopen("G:\\PATdata\\A1081.txt","r",stdin);
	while(cin>>n){
		ans.zi=0,ans.mu=1;
		while(n--){
			scanf("%lld/%lld",&temp.zi,&temp.mu);
			ans=add(ans,temp);
		}
		show(ans);
	}
	return 0;
}