#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=100000+1;
struct Man{
	int id;
	char name[10];
	int grade;
}man[maxn];
bool cmp1(Man a,Man b){
	return a.id<b.id;
}
bool cmp2(Man a,Man b){
	if(strcmp(a.name,b.name)!=0)
		return strcmp(a.name,b.name)<0;
	else 
		return a.id<b.id;
}
bool cmp3(Man a,Man b){
	if(a.grade!=b.grade)
		return a.grade<b.grade;
	else 
		return a.id<b.id;
}
int main(){
	int n,c;
	freopen("G:\\PATdata\\A1028.txt","r",stdin);
	scanf("%d %d",&n,&c);
	for(int i=0;i<n;i++){
		scanf("%d %s %d",&man[i].id,man[i].name,&man[i].grade);
	}
	if(c==1){
		sort(man,man+n,cmp1);
		for(int i=0;i<n;i++){
				printf("%06d %s %d\n",man[i].id,man[i].name,man[i].grade);
		}
	}else if(c==2){
		sort(man,man+n,cmp2);
		for(int i=0;i<n;i++){
				printf("%06d %s %d\n",man[i].id,man[i].name,man[i].grade);
		}
	}else if(c==3){
		sort(man,man+n,cmp3);
		for(int i=0;i<n;i++){
				printf("%06d %s %d\n",man[i].id,man[i].name,man[i].grade);
		}
	}
	
	return 0;
}


