#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
const int maxn=1e5+1;
char s[maxn];
int leftP[maxn]={0};
int main(){
	freopen("G://PATdata//A1093.txt","r",stdin);
	gets(s);
    int len=strlen(s);	
	int rightT=0,sum=0;	
			for(int j=0;j<len;j++){	
				if(j>0)
					leftP[j]=leftP[j-1];
				if(s[j]=='P')
					leftP[j]++;
			}
			for(int j=len-1;j>=0;j--){	
				if(s[j]=='T')//////////
					rightT++;
				else if(s[j]=='A'){
					sum=(sum+leftP[j]*rightT)%1000000007;//////////////这里mod，防止先溢出了导致sum变负
				}

			}
		
	printf("%d\n",sum);
	
	return 0;
}