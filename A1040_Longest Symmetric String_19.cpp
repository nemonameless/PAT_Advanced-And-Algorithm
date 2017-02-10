#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<cctype>
#include<algorithm>
#include<cmath>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<stack>
using namespace std;
const int maxn=1010;
char str[maxn];
int main(){
	//freopen("G:\\PATdata\\A1040.txt","r",stdin);
	while(gets(str)){
	int len=strlen(str);
	int maxlen=1;
	if(len==1){
		maxlen=1;
	}else{
		for(int i=0;i<len;i++){
			int cnt=0,tmplen=0;
			for(int j=len-1;j>i;j--){
				if(str[i]==str[j] ){
					cnt++;
					i++;
					tmplen=2*cnt;
					if(j-i==2){
						tmplen+=2;
						break;
					}else if(j-i==1){
						tmplen++;
						break;
					}
				}
			}
			if(tmplen>maxlen){
				maxlen=tmplen;
			}
		}
	}
	printf("%d\n",maxlen);
	}
	return 0;
}