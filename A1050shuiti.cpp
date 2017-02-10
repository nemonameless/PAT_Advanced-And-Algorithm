#include<cstdio>
#include<cstring>
#include<cctype>
#include<algorithm>
using namespace std;
char s1[10001],s2[10001];
bool hass[129];//////////不能取名为hash.编译器问题
int main(){
	gets(s1);gets(s2);
	int len1=strlen(s1);
	int len2=strlen(s2);
	for(int i=0;i<129;i++)
		hass[i]=false;
	for(int i=0;i<len1;i++){
		hass[s1[i]]=true;
	}
	for(int i=0;i<len2;i++){
		hass[s2[i]]=false;
	}
	for(int i=0;i<len1;i++){
		if(hass[s1[i]]==true)
			printf("%c",s1[i]);
	}
	
	return 0;
}
