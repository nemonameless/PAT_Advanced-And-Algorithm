#include<cstdio>
#include<string>
#include<cstring>
using namespace std;
const int maxn=10000;
int main(){
	char s[maxn];
	freopen("G:\\PATdata\\A1073.txt","r",stdin);
	while(gets(s)){
	int len=strlen(s);
	if(s[0]=='-')
		printf("-");
	int pos=0;
	for(int i=1;i<len;i++)
		if(s[i]=='E')
			pos=i;
	int exp=0;
	for(int i=pos+2;i<len;i++){
		exp=10*exp+s[i]-'0';
	}
	if(exp==0){////////////////////////////////////////
		for(int i=1;i<pos;i++)
			printf("%c",s[i]);
	}

	if(s[pos+1]=='-' && exp>0){
		printf("0.");
		for(int i=0;i<exp-1;i++)
			printf("0");
		printf("%c",s[1]);
		for(int i=3;i<pos;i++)
			printf("%c",s[i]);
	}
	if(s[pos+1]=='+' && exp>0){
		printf("%c",s[1]);
		for(int i=3;i<pos;i++){
			printf("%c",s[i]);
			if(i==exp+2 && pos-3!=exp)////////特殊情况，否则扣2分//////////==而不是=
				printf(".");
		}
		for(int i=0;i<exp-(pos-2-1);i++)
			printf("0");
	}
	printf("\n");
	}

	return 0;
}