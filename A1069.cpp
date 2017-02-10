#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
bool cmp2(int a,int b){
	return a>b;
}
void toarray(int n,int num[]){
	for(int i=0;i<4;i++){
		num[i]=n%10;
		n/=10;
	}
}
int tonum(int num[]){
	int sum=0;     ////////////////
	for(int i=0;i<4;i++){
		sum=sum*10+num[i];
	}
	return sum;
}

int main(){
	int n,min,max;
	scanf("%d",&n);
	int num[5];
	while(1){
		toarray(n,num);
		sort(num,num+4,cmp2);
		max=tonum(num);
		sort(num,num+4);
		min=tonum(num);
		n=max-min;

		printf("%04d - %04d = %04d\n",max,min,n);
		if(n==6174 || n==0)///////////
			break;
	}
	return 0;
}

