#include<cstdio>
#include<cstring>
using namespace std;
const int maxn=257;
char s[101][maxn]={};
int minlen=256;
int main(){
	int k,cnt=0;
	freopen("G:\\PATdata\\A1077.txt","r",stdin);
	scanf("%d",&k);
	getchar();
	for(int i=0;i<k;i++){
		gets(s[i]);
		int len=strlen(s[i]);
		if(len<minlen)
			minlen=len;
		for(int j=0;j<len/2;j++){
			char tmp=s[i][j];
			s[i][j]=s[i][len-1-j];
			s[i][len-1-j]=tmp;
		}
	}
	for(int i=0;i<minlen;i++){
		char c=s[0][i];
		bool same=true;
		for(int j=1;j<k;j++){
			if(s[j][i]!=c){
				same=false;
				break;
			}
		}
		if(same)
			cnt++;
		else
			break;
	}
	if(cnt){
		for(int i=cnt-1;i>=0;i--){
			printf("%c",s[0][i]);
		}
	}else{
		printf("nai");
	}
	return 0;
}


