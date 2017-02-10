#include<cstdio>
struct person{
	char name[10];
	int score;
	char id[16];
}tmp,M,F;

int main(){
	int n;
	freopen("G:\\PATdata\\A1036.txt","r",stdin);
	scanf("%d",&n);
	char c;
	M.score=101;
	F.score =-1;
	for(int i=0;i<n;i++){
		scanf("%s %c %s %d",tmp.name,&c,tmp.id,&tmp.score);
		if(c=='M' && tmp.score <=M.score){
			M=tmp;                             ///////要整体相等，不仅是分数相等
		}
		if(c=='F' && tmp.score >=F.score){
			F=tmp;
		}
	}
	if(F.score==-1 || M.score==101){
		if(F.score==-1)
			printf("Absent\n");
		else
			printf("%s %s\n",F.name ,F.id );
		if(M.score==101)
			printf("Absent\n");
		else
			printf("%s %s\n",M.name ,M.id );
		printf("NA\n");
	}
	else{
		printf("%s %s\n",F.name ,F.id );
		printf("%s %s\n",M.name ,M.id );
		printf("%d\n",F.score-M.score );
	}
	return 0;
}