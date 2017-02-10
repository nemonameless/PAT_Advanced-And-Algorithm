#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=10001;
struct Man{
	char name[10];
	int h;
}man[maxn],final[maxn];
bool cmp(Man a,Man b){
	if(a.h!=b.h)
		return a.h>b.h;
	else
		return strcmp(a.name,b.name)<0;
}
int main(){
	int n,k;
//	freopen("G:\\PATdata\\A1109.txt","r",stdin);
	scanf("%d %d",&n,&k);
	for(int i=0;i<n;i++){
		scanf("%s %d",man[i].name,&man[i].h);
	}
	sort(man,man+n,cmp);
	int extra=n%k;
	int pos=0;
	for(int i=0;i<k;i++){
		int list=n/k;
		if(i==0){
			list+=extra;
		}
		int now=list/2,f=-1;
		final[now]=man[pos++];

		while(now>=0 && now<list){
			now=now+f;
			if(now>=0 && now<list){
				final[now]=man[pos++];
				f=-f;
				if(f>0)
					f++;
				else
					f--;
			}else
				break;
		}
		for(int j=0;j<list;j++){
			printf("%s",final[j].name);
			if(j<list-1)
				printf(" ");
			else
				printf("\n");
		}
	}
	return 0;
}