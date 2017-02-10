#include<cstdio>
#include<cstring>
using namespace std;
const int maxn=1001;
struct Man{
	char name[11];
	char pw[11];
	bool flag;
}man[maxn];
int main(){
	int k,cnt=0;
	
	//freopen("G:\\PATdata\\A1035.txt","r",stdin);
	scanf("%d",&k);
	for(int i=0;i<k;i++){
		scanf("%s %s",man[i].name,man[i].pw);
		int len=strlen(man[i].pw);
		for(int j=0;j<len;j++){
			if(man[i].pw[j]=='1'){
				man[i].pw[j]='@';
				man[i].flag=true;
			}
			if(man[i].pw[j]=='0'){
				man[i].pw[j]='%';
				man[i].flag=true;
			}
			if(man[i].pw[j]=='l'){
				man[i].pw[j]='L';
				man[i].flag=true;
			}
			if(man[i].pw[j]=='O'){
				man[i].pw[j]='o';
				man[i].flag=true;
			}
		}
		if(man[i].flag==true)///////////////////·ÅÔÚÍâ±ß
				cnt++;

	}
	if(cnt==0 && k==1)
		printf("There is 1 account and no account is modified\n");
	else if(cnt==0)
		printf("There are %d accounts and no account is modified\n",k);///xiaoxin
	else{
		printf("%d\n",cnt);
		for(int i=0;i<k;i++){
			if(man[i].flag==true)
				printf("%s %s\n",man[i].name,man[i].pw);
		}
	}
	return 0;
}


