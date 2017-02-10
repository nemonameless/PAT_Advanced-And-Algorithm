#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int has[40]={};
int str2num(char a[]){
	int num=0;
	int len=strlen(a);
	for(int i=0;i<len;i++){
		num+=a[i]-'0';
	}
	return num;
}
int main(){
	int n,cnt=0;
	char a[5];
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%s",a);
		int data=str2num(a);
		has[data]++;
		
	}
	for(int i=0;i<40;i++){
		if(has[i]>0)
			cnt++;
	}
	printf("%d\n",cnt);
	//sort(has,has+40);
	int nnn=0;
	for(int i=0;i<40;i++){
		if(has[i]>0){
			printf("%d",i);
			nnn++;
			if(nnn<cnt)
				printf(" ");
		}
		
	}

	return 0;
}