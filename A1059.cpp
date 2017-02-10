#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
const int maxn=11111;
bool isprime(long long int n){
	if(n<=1)
		return false;
	long long int s=(int)sqrt(1.0*n);
	for(int i=2;i<=s;i++){
		if(n%i==0)
			return false;
	}
	return true;

}
bool in[maxn]={false};
struct Node{
	int id;
	int num;
}node[1000];
int main(){
	long long int n;
//	freopen("G:\\PATdata\\A1059.txt","r",stdin);
	scanf("%lld",&n);
	printf("%lld=",n);
	if(isprime(n)){
		printf("%lld\n",n);
		return 0;
	}
	if(n==1){
		printf("%lld\n",n);
		return 0;
	}
	int len=0;
	int s=(int)sqrt(1.0*n);
	for(int i=2;i<=s;i++){
		if(isprime(i) && n%i==0){
			while(n%i==0){
				node[len].id=i;
				node[len].num++;
				n/=i;
			}
			len++;
		}	
	}
	node[len].id=n;
	node[len].num=1;
	
	for(int i=0;i<len;i++){
		printf("%d",node[i].id);
		if(node[i].num>1)
			printf("^%d",node[i].num);
		if(i<len-1)
			printf("*");
	}
	printf("\n");
	return 0;
}