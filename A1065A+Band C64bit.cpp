#include<cstdio>
using namespace std;
int main(){
	int n;
	long long a,b,c;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%lld%lld%lld",&a,&b,&c);
		long long res=a+b;
		bool flag;
		if(res<0 && a>0 &&b>0)
			flag=true;
		else if(a<0 &&b<0 && res>=0)
			flag=false;
		else if(res>c)
			flag =true;
		else
			flag=false;
		if(flag==true)
			printf("Case #%d: true\n",i+1);
		else
			printf("Case #%d: false\n",i+1);
	}
	return 0;
}