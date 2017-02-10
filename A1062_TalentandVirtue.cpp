#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
struct Man{
	char id[10];
	int v_score;
	int t_score;
	int rank,list;
	int total;
}man[100010];
bool cmp(Man a,Man b){
	if(a.list!=b.list)
		return a.list<b.list;
	else if(a.total!=b.total)
		return a.total>b.total;
	else if(a.v_score!=b.v_score)
		return a.v_score>b.v_score;
	else
		return strcmp(a.id,b.id)<0;
}
int main(){
	int n,L,H;
	freopen("G:\\PATdata\\A1062.txt","r",stdin);
	scanf("%d %d %d",&n,&L,&H);
	int num=0;
	for(int i=0;i<n;i++){
		scanf("%s %d %d",man[i].id,&man[i].v_score,&man[i].t_score);
		man[i].total=man[i].v_score+man[i].t_score;
		if(man[i].v_score<L || man[i].t_score<L){/////////////不及格情况放第一个判断
			man[i].list=4;
		}else if(man[i].v_score>=H && man[i].t_score>=H){
			man[i].list=0;
			num++;
		}else if(man[i].v_score>=H && man[i].t_score<H){
			man[i].list=1;
			num++;
		}else if(man[i].v_score<H && man[i].t_score<H && man[i].v_score>=man[i].t_score){
			man[i].list=2;
			num++;
		}else{
			man[i].list=3;
			num++;
		}
	}
	sort(man,man+n,cmp);
	printf("%d\n",num);
	for(int i=0;i<num;i++){
		printf("%s %d %d\n",man[i].id,man[i].v_score,man[i].t_score);
	}

	return 0;
}