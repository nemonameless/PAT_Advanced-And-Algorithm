#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int main(){
	char str[240],ans[40][40];
	freopen("G:\\PATdata\\A1031.txt","r",stdin);
	scanf("%s",&str);  //gets(str);
	int len=strlen(str);
	int n1=(len+2)/3;////////////////////////
	int n3=n1;
	int n2=len-2*n1+2;
	for(int i=1;i<=n1;i++){
		for(int j=1;j<=n2;j++)
			ans[i][j]=' ';
	}
	int pos=0;
	for(int i=1;i<=n1;i++)
		ans[i][1]=str[pos++];
	for(int j=2;j<=n2;j++)
		ans[n1][j]=str[pos++];
	for(int i=n3-1;i>=1;i--){
		ans[i][n2]=str[pos++];
	}
	for(int i=1;i<=n1;i++){
		for(int j=1;j<=n2;j++)
			printf("%c",ans[i][j]);
		printf("\n");
	}
	return 0;
}