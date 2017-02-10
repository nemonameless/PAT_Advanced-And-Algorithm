#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=1010;
int father[maxn];
int isroot[maxn]={0};
int course[maxn]={0};
bool cmp(int a,int b){
	return a>b;
}
int n,k;
void init(int n){
	for(int i=1;i<=n;i++){
		isroot[i]=false;
		father[i]=i;
	}
}
int findfather(int x){
	int a=x;
	while(x!=father[x])
		x=father[x];
	while(a!=father[a]){
		int z=a;
		a=father[a];
		father[z]=x;
	}
	return x;
}
void Union(int a,int b){
	int faA=findfather(a);
	int faB=findfather(b);
	if(faA!=faB)
		father[faA]=faB;
}

int main(){
//	freopen("G:\\PATdata\\A1107.txt","r",stdin);
	scanf("%d",&n);
	int h;
	init(n);/////////////////////////////
	for(int i=1;i<=n;i++){
		scanf("%d:",&k);
		for(int j=0;j<k;j++){
			scanf("%d",&h);
			if(course[h]==0)
				course[h]=i;
			Union(i,findfather(course[h]));	////////////////////////小心不要加在这层for的下面 
		}
		
	}
	for(int i=1;i<=n;i++){
		isroot[findfather(i)]++;
	}
sort(isroot+1,isroot+1+n,cmp);
	int ans=0;
	for(int i=1;i<=n;i++){
		if(isroot[i]!=0)
			ans++;
	}
	printf("%d\n",ans);
	
	for(int i=1;i<=ans;i++){
		printf("%d",isroot[i]);
		if(i<ans)
			printf(" ");
		else
			printf("\n");
	}
	return 0;
}

