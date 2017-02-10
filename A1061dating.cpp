#include<cstdio>
#include<cstring>
#include<cctype>
int main(){
	char week[7][5]={"MON","TUE","WED","THU","FRI","SAT","SUN"};
	char s1[70],s2[70],s3[70],s4[70];
	gets(s1);gets(s2);gets(s3);gets(s4);
	int len1=strlen(s1),len2=strlen(s2),len3=strlen(s3),len4=strlen(s4);
	int i;
	for(i=0;i<len1 && i<len2;i++){
		if(s1[i]==s2[i]&& s1[i]>='A'&& s1[i]<='G'){
			printf("%s ",week[s1[i]-'A']);
			break;
		}
	}
	for(i++;i<len1 && i<len2 ;i++){
		if(s1[i]==s2[i]&& s1[i]>='0'&& s1[i]<='9'){
			printf("%02d:",s1[i]-'0');
			break;
		}else if(s1[i]==s2[i] && s1[i]>='A'&& s1[i]<='N'){
			printf("%02d:",s1[i]-'A'+10);///////+10
			break;
		}	
	}
	for(i=0;i<len3 && i<len4;i++){
		if(s3[i]==s4[i]){
			if(isalpha(s3[i])){
				printf("%02d",i);
				break;
			}
		}
	}
	return 0;
}