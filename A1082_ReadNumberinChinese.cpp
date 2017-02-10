#include <cstdio>
#include <cstring>
char unit[10][6]={"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};
char wei[5][5] = {"Shi", "Bai", "Qian", "Wan", "Yi"};
int main(){
	int n;
	char s[11];
   gets(s);
	int len=strlen(s);
	int left=0,right=len-1;
	if(s[0]=='-'){
		printf("Fu");
		left++;
	}
	while(left+4<=right){
		right-=4;
	}
	while(left <  len){/////////////
		bool flag=false;
		bool isprint=false;
		while(left<=right){/////////
			if(left>0 && s[left]=='0')
				flag=true;
			else{
				if(flag==true){
					printf(" ling");
					flag=false;
				}
				if(left>0){
					printf(" ");
				}
				printf("%s",unit[s[left]-'0']);
				isprint=true;
				if(left!=right){
					printf(" %s",wei[right-left-1]);
				}
			}
			left++;
		}
		if(isprint==true && right !=len-1){
			printf(" %s",wei[(len-1-right)/4+2]);
		}
		right+=4;
	}
    return 0;
}