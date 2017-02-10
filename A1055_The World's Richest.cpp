#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cctype>
using namespace std;
const int maxn=1e5+1;
struct Man{
	char name[9];
	int age,worth;
}man[maxn],tmp[maxn];
bool cmp(Man a,Man b){
	if(a.worth!=b.worth)
		return a.worth>b.worth;
	else if(a.age!=b.age)
		return a.age<b.age;
	else 
		return strcmp(a.name,b.name)<0;
}
int main(){
	int n,m,young,old,k;
		//freopen("G:\\PATdata\\A1055.txt","r",stdin);
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++){
		scanf("%s%d%d",man[i].name,&man[i].age,&man[i].worth);
	}
	sort(man,man+n,cmp);
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&k,&young,&old);
		int num=0;
		printf("Case #%d:\n",i);

		for(int j=0;j<n && num<k;j++){      /////////////////&& num<k
			if(man[j].age<=old && man[j].age>=young){			
				printf("%s %d %d\n",man[j].name,man[j].age,man[j].worth);
				num++;
			}
		}
		if(num==0)
			printf("None\n");
	}


	return 0;
}


