#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct Stu{
	char id[15];
	int score;
	int local_rank;
	int location;
	int final_rank;
}stu[30010];
bool cmp(Stu a,Stu b){
	if(a.score!=b.score)
		return a.score>b.score;
	else
		return strcmp(a.id,b.id)<0;
}
int main(){
	int n,k,num=0;
	freopen("G:\\PATdata\\A1025.txt","r",stdin);
	scanf("%d",&n);
	for(int i=1;i<n+1;i++){ ////////////////1,n+1
		scanf("%d",&k);
		for(int j=0;j<k;j++){
			scanf("%s %d",stu[num].id,&stu[num].score);///////////
			stu[num].location=i;
			num++;
		}
		sort(stu+num-k,stu+num,cmp);
		stu[num-k].local_rank=1;
		for(int j=num-k+1;j<num;j++){
			if(stu[j].score==stu[j-1].score)
				stu[j].local_rank =stu[j-1].local_rank;
			else
				stu[j].local_rank =j+1-(num-k);/////////////////////
		}
	}
	sort(stu,stu+num,cmp);
	printf("%d\n",num);

	/*//
	stu[0].final_rank=1;
	for(int j=0;j<num;j++){
		if(j>0 && stu[j].score==stu[j-1].score)
				stu[j].final_rank =stu[j-1].final_rank;
			else
				stu[j].final_rank =j+1;//////////////////////////
		printf("%s %d %d %d\n",stu[j].id ,stu[j].final_rank,stu[j].location,stu[j].local_rank);
	}
	*/
	int r=1;
	for(int j=0;j<num;j++){
		if(j>0 && stu[j].score!=stu[j-1].score)
			r=j+1;  //////////////////////////////////////不是r++，也不是r=r+j
		printf("%s %d %d %d\n",stu[j].id ,r,stu[j].location,stu[j].local_rank);
	}
	return 0;
}

