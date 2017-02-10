
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=100000+1;
struct Man{
	char name[11];
	char id[11];
	int worth;
}man[maxn],tmp[maxn];
bool cmp(Man a,Man b){
	return a.worth >b.worth;
}
int main(){
	int n,amin,amax;
	freopen("G:\\PATdata\\A1083.txt","r",stdin);
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%s %s %d",man[i].name,man[i].id,&man[i].worth);
	}
	scanf("%d %d",&amin,&amax);
	int num=0;
	for(int i=0;i<n;i++){
		if(man[i].worth <=amax && man[i].worth>=amin){
			tmp[num]=man[i];
			num++;

		}
	}
		if(num==0){
				printf("NONE\n");
			}else{
			//	printf("%d\n",num);
				sort(tmp,tmp+num,cmp);
			}
				for(int z=0;z<num;z++){///////////////
					printf("%s %s\n",tmp[z].name,tmp[z].id);
				}
	return 0;
}
