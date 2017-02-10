#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
const int maxn=1e5+1;
char s[maxn];
int leftP[maxn]={0},rightT=0;
int main(){
	//freopen("G://PATdata//A1029.txt","r",stdin);
	gets(s);
    int len=strlen(s);
	
	int k=0,sum=0;
	for(int i=0;i<len;i++){
		if(s[i]=='A'){
			k=i;		
			for(int j=0;j<=k;j++){	
				if(s[0]=='P')/////////////////
					leftP[0]=1;
				else
					leftP[0]=0;
				if(j>0 && s[j]=='P')
					leftP[j]=leftP[j-1]+1;
				else
					leftP[j]=leftP[j-1];
			}
			for(int j=len-1;j>=k;j--){	
				if(s[j]=='T')//////////
					rightT++;
			}
		
		if(leftP[k]>0 && rightT>0)
			sum=sum+leftP[k]*rightT;////////////////放在if(s[i]=='A'){}中才对
			rightT=0;
		}
		
	}
	printf("%d\n",sum%1000000007);
	
	return 0;
}