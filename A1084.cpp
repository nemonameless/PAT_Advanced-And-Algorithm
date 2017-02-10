#include<cstdio>
#include<cstring>
#include<cctype>
using namespace std;
int main(){
	char s1[81],s2[81];
	gets(s1);
	gets(s2);
	int len1=strlen(s1);
	int len2=strlen(s2);
	bool hash[129];
	for(int i=0;i<129;i++)
		hash[i]=false;
	for(int i=0;i<len2;i++){
		if(isalpha(s2[i]))
			s2[i]=toupper(s2[i]);
		hash[s2[i]]=true;
	}
	for(int i=0;i<len1;i++){
		if(isalpha(s1[i]))
			s1[i]=toupper(s1[i]);
		if(hash[s1[i]]==false){
			printf("%c",s1[i]);
			hash[s1[i]]=true;
		}
	}
	return 0;
}

