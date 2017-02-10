#include<cstdio>
#include<cstring>
using namespace std;
char num[10][10]={"zero","one","two","three","four","five","six","seven","eight","nine"};///zero
char s[110];
int main(){
	
	gets(s);
	int sum=0,len=strlen(s);
	for(int i=0;i<len;i++){
		sum+=s[i]-'0';
	}
	int sep[11]={};
	int cnt=0;
	if(sum==0) //////////////////////
		printf("%s",num[0]);////////////////不是s[0]
	else{
		while(sum!=0){
			sep[cnt++]=sum%10;
			sum/=10;
		}
		for(int i=cnt-1;i>=0;i--){
			printf("%s",num[sep[i]]);/////////////num[sep[i]]不是num[i]
			if(i>0)
				printf(" ");
		}
	}
	return 0;
}


