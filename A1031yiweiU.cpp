
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int main(){
	char str[240];
	freopen("G:\\PATdata\\A1031.txt","r",stdin);
	scanf("%s",&str);
	int len=strlen(str);
	int n1=(len+2)/3;////////////////////////
	int n3=n1;
	int n2=len-2*n1+2;
	for(int i=0;i<n1-1;i++){
		printf("%c",str[i]);
		for(int j=0;j<n2-2;j++)///////////////
			printf(" ");
		printf("%c\n",str[len-1-i]);
	}
	for(int i=0;i<n2;i++)
		printf("%c",str[n1-1+i]);
	return 0;
}