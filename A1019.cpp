#include<cstdio>
#include<cstring>
using namespace std;
int main(){
	int n,b;
	scanf("%d %d",&n,&b);
	int ans[32]={};
	int num=0;
	do{
		ans[num++]=n%b;
		n=n/b;
	}while(n!=0);
	bool flag=1;
	for(int i=0;i<num/2;i++){
		if(ans[i]!=ans[num-1-i])
			flag=0;
	}
	if(flag==0)
		printf("No\n");
	else
		printf("Yes\n");
	for(int i=num-1;i>=0;i--){
		printf("%d",ans[i]);
		if(i>0)
			printf(" ");
	}
	return 0;
}