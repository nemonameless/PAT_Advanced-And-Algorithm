#include<cstdio>
#include<cstring>
#include<cctype>
#include<algorithm>
using namespace std;
char s1[1001],s2[1001];
int hass[129];//////////不能取名为hash.编译器问题
int main(){
	gets(s1);gets(s2);
	int len1=strlen(s1);
	int len2=strlen(s2);
	for(int i=0;i<129;i++)
		hass[i]=0;
	for(int i=0;i<len2;i++){
		hass[s2[i]]++;
	}
	int num=0;
	for(int i=0;i<len1;i++){
		if(hass[s1[i]]>0){
			hass[s1[i]]--;
			num++;
		}
	}
	if(num==len2)
		printf("Yes %d",len1-len2);	
	else
		printf("No %d",len2-num);
	return 0;
}

