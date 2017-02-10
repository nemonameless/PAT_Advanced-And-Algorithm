#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=10000+1;
struct Man{
	int id;
	int problem_score[6];
	int score;
	int solved;
	bool flag;
	//int rank;
}man[maxn];
bool cmp(Man a,Man b){
	if(a.score!=b.score)
		return a.score>b.score;
	else if(a.solved!=b.solved)
		return a.solved>b.solved;
	else 
		return a.id<b.id;
}
int main(){
	int n,k,m,p_score[6]={0};
	freopen("G:\\PATdata\\A1075.txt","r",stdin);
	scanf("%d %d %d",&n,&k,&m);
	for(int i=1;i<=k;i++){
		scanf("%d",&p_score[i]);
	}
	for(int i=1;i<=n;i++){
		man[i].id=i;
		man[i].score=0;
		man[i].flag=false;
		man[i].solved=0;
		memset(man[i].problem_score,-1,sizeof(man[i].problem_score));
	}


	int u_id,p_id,score_obtained;
	for(int i=0;i<m;i++){
		scanf("%d %d %d",&u_id,&p_id,&score_obtained);
		if(score_obtained !=-1){
			man[u_id].flag=true;
		}
		if(score_obtained==-1 && man[u_id].problem_score[p_id]==-1){
			man[u_id].problem_score[p_id]=0;
		}
		if(score_obtained==p_score[p_id] && man[u_id].problem_score[p_id]<p_score[p_id]){
			man[u_id].solved++;
		}
		if(score_obtained > man[u_id].problem_score[p_id]){
			man[u_id].problem_score[p_id]=score_obtained;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=k;j++){
			if(man[i].problem_score[j] !=-1){
				man[i].score += man[i].problem_score[j];
			}
		}
	}
	sort(man+1,man+n+1,cmp);
	int r=1;
	for(int i=1;i<=n && man[i].flag==true ;i++){
		if(i>1 && man[i].score!=man[i-1].score)
			r=i;
		printf("%d %05d %d",r,man[i].id,man[i].score);
		for(int j=1;j<=k;j++){
			if(man[i].problem_score[j]==-1)
				printf(" -");
			else
				printf(" %d",man[i].problem_score[j]);
		}
		printf("\n");
			
	}
	return 0;
}





