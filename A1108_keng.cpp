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
bool judge(char str[]){
	int i=0,dot=-1,dotcnt=0;//////////////////dot一定要是-1
	int len=strlen(str);
	while(i<len){
		if(isalpha(str[i]))
			return false;
		if(str[i]=='-'){
			if(i>0)//////////////////////
				return false;
		}
		if(str[i]=='.'){
			dotcnt++;
			dot=i;
		}
		if(dotcnt>=2)
				return false;
		if(i-dot>2 &&dot>=0)
				return false;
		i++;//////////////////////////////////////////
	}
	return true;
}
bool check(char tmp[]){
	int dot=-1;
	for(int i=0;tmp[i];i++){
		if(tmp[i]=='.'){
			if(dot>=0)
				return false;
			dot=i;
		}else if(tmp[i]=='-'){
			if(i>0)
				return false;
		}else if(!isdigit(tmp[i])){
			return false;
		}
		if(dot>=0 && i-dot>2)
			return false;
	}
	return 1;
}
char str[20];
int main(){
	int n;
	//freopen("G:\\PATdata\\A1108.txt","r",stdin);
	scanf("%d",&n);
	//getchar();
	double ans=0;
	double x;
	int cnt=0;
	for(int i=0;i<n;i++){
		scanf("%s",str);
		//cout<<check(str);

		if(judge(str)){
			sscanf(str,"%lf",&x);
			//cout<<x<<endl;
			if(x>=-1000 && x<=1000){
				ans+=x;
				cnt++;
			}else
				printf("ERROR: %s is not a legal number\n",str);
		}else{
			printf("ERROR: %s is not a legal number\n",str);
		}
	}
	if(cnt==0)
		printf("The average of 0 numbers is Undefined\n");
	else if(cnt==1)
		printf("The average of 1 number is %.2f\n",ans);
	else
		printf("The average of %d numbers is %.2f\n",cnt,ans/cnt);
	return 0;
}