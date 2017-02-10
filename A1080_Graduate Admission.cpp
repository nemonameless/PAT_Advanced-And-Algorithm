#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=40010;
struct Man{
	int ge,gi,sum;
	int r,manID;
	int cho[6];
}man[maxn];
struct School{
	int quota;
	int stuNum;
	int id[40010];
	int lastAdmit;
}sch[101];
bool cmpStu(Man a,Man b){
	if(a.sum!=b.sum)
		return a.sum>b.sum;
	else 
		return a.ge>b.ge;
}
bool cmpID(int a,int b){
	return man[a].manID<man[b].manID;
}
int main(){
	int n,m,k;
	freopen("G:\\PATdata\\A1080.txt","r",stdin);
	scanf("%d %d %d",&n,&m,&k);
	for(int i=0;i<m;i++){
		scanf("%d",&sch[i].quota);
		sch[i].stuNum=0;
		sch[i].lastAdmit=-1;
	}
	for(int i=0;i<n;i++){
		man[i].manID=i;
		scanf("%d %d",&man[i].ge,&man[i].gi);
		man[i].sum=man[i].ge+man[i].gi;
		for(int j=0;j<k;j++){
			scanf("%d",&man[i].cho[j]);
		}
	}
	sort(man,man+n,cmpStu);
	for(int i=0;i<n;i++){
		if(i>0 && man[i].sum == man[i-1].sum && man[i].ge == man[i-1].ge)//////////////
			man[i].r=man[i-1].r;/////////////////////
		else
			man[i].r=i;
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<k;j++){
			int choice=man[i].cho[j];
			int num=sch[choice].stuNum;
			int last=sch[choice].lastAdmit;
			if(num<sch[choice].quota || (last!=-1 && man[i].r==man[last].r)){
				sch[choice].id[num]=i;	
				sch[choice].lastAdmit=i;
				sch[choice].stuNum++;
				break;
			}
		}
	}
	for(int i=0;i<m;i++){
		if(sch[i].stuNum!=0){
			sort(sch[i].id,sch[i].id+sch[i].stuNum,cmpID);
			for(int j=0;j<sch[i].stuNum;j++){
				printf("%d",man[sch[i].id[j]].manID);
				if(j<sch[i].stuNum-1)
					printf(" ");
			}
		}
		printf("\n");
	}
	return 0;
}







