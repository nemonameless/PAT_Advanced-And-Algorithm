#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
const int maxn=40010;
const int maxm=26*26*26*10+1;
vector<int> sel_course[26*26*26*10+1];///////////
int getid(char name[]){
	int id=0;
	for(int i=0;i<3;i++){
		id=id*26+name[i]-'A';
	}
	id=id*10+name[3]-'0';
	return id;
}

int main(){
	int n,k;
	char name[5];
		//freopen("G:\\PATdata\\A1039.txt","r",stdin);
	scanf("%d %d",&n,&k);

	
	for(int i=0;i<k;i++){
		int course,num;
		scanf("%d %d",&course,&num);
		for(int j=0;j<num;j++){
			scanf("%s",name);
			int id=getid(name);
			sel_course[id].push_back(course);
		}
	}
	
	for(int i=0;i<n;i++){
		scanf("%s",name);
		int id=getid(name);
		sort(sel_course[id].begin(),sel_course[id].end());
		printf("%s %d",name,sel_course[id].size());
		for(int j=0;j<sel_course[id].size();j++){
			printf(" %d",sel_course[id][j]);
		}
		printf("\n");
	}
	return 0;
}
