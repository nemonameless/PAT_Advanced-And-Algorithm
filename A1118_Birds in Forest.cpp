#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int maxn=10010;
int father[maxn];
int isroot[maxn]={0};
bool bird[maxn]={false};
int tree[maxn]={0};
int n,q,k;
void init(int n){
	for(int i=1;i<=n;i++){
		isroot[i]=false;
		father[i]=i;
	}
}
int findFather(int x){
	int a=x;
	while(x!=father[x])//////////////////////////////////不加会超时
		x=father[x];
	while(a!=father[a]){
		int z=a;
		a=father[a];
		father[z]=x;
	}
	return x;
}
void Union(int a,int b){
	int faA=findFather(a);
	int faB=findFather(b);
	if(faA!=faB)
		father[faA]=faB;
}
int main(){
	freopen("G:\\PATdata\\A1118.txt","r",stdin);
	scanf("%d",&n);
	init(n);
	int h;
	int numbird=0;
	for(int i=1;i<=n;i++){
	scanf("%d",&k);
		for(int j=0;j<k;j++){
			scanf("%d",&h);
			if(bird[h]==false){
				numbird++;
				bird[h]=true;
			}
			if(tree[h]==0){
				tree[h]=i;
			}
			//printf("%d\n",findFather(tree[h]));
			Union(i,findFather(tree[h]));/////////这句放这个括号下会显示有3棵树，，但还是能得3分
		}
	//	printf("..............\n");
		
	}
	int numtree=0;
	for(int i=1;i<=n;i++){
		//printf("%d.1111\n",findFather(i));
		isroot[findFather(i)]++;
	}



	for(int i=1;i<=n;i++){
		if(isroot[i]!=0)
			numtree++;
	}
	
	 printf("%d %d\n", numtree, numbird);


	scanf("%d",&q);
	int ida,idb;	
	for(int i=0;i<q;i++){
		scanf("%d%d", &ida, &idb);
		if((bird[ida] &&bird[idb]) && findFather(tree[ida]) == findFather(tree[idb])) {//////////////////////用cin cout会超时
            printf("Yes\n");
        } else {
            printf("No\n");
        }
	}
	return 0;
}


