#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
const int maxn=40010;
const int maxc=2510;
vector<int> sel_course[maxc];///////////
char name[maxn][5];
bool cmp(int a,int b){
	return strcmp(name[a],name[b])<0;
}
int main(){
	int n,k,num,course_id;
	//freopen("G:\\PATdata\\A1047.txt","r",stdin);
	scanf("%d %d",&n,&k);
	for(int i=0;i<n;i++){
		scanf("%s %d",name[i],&num);
		for(int j=0;j<num;j++){
			scanf("%d",&course_id);
			sel_course[course_id].push_back(i);
		}
	}
	for(int i=1;i<=k;i++){
		printf("%d %d\n",i,sel_course[i].size());
		sort(sel_course[i].begin(),sel_course[i].end(),cmp);

		for(int j=0;j<sel_course[i].size();j++){
			printf("%s\n",name[sel_course[i][j]]);////////////
		}
	}
	return 0;
}
