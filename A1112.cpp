#include<cstdio>
#include<cstring>
using namespace std;
char s[1001];
int has[130]={0};
int main(){
	int n;
//		freopen("G:\\PATdata\\A1112.txt","r",stdin);
	scanf("%d",&n);
	getchar();////////////////////////////////不加会无法读入 
	gets(s);
	int len=strlen(s);
	for(int i=0,j=0;i<len;i=j){
		while(s[j] && s[i]==s[j])
			j++;
		if((j-i)%n != 0)
			has[s[i]]=-1;
		else if(has[s[i]]==0)
			has[s[i]]=1;
	}
	for(int i=0;i<len;i++){
		if(has[s[i]]==1){
			printf("%c",s[i]);
			has[s[i]]=2;
		}
	}
	printf("\n");
	for(int i=0;i<len;i++){
		printf("%c",s[i]);
		if(has[s[i]]==2)
			i+=n-1;
	}
	return 0;
}

