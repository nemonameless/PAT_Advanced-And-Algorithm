#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int maxn=10001;
int father[maxn];
int isroot[maxn]={0};
bool live[maxn]={false};
bool shown[maxn]={false};
int family[maxn]={0};
int n,q,k;
void init(int n){
	for(int i=1;i<=n;i++){
		isroot[i]=false;
		father[i]=i;
	}
}
int findFather(int x){
	int a=x;
	if(x!=father[x])
		x=father[x];
	 while(a != father[a]) {
        int z = a;
        father[a] = x;
        a = father[z];
    }
	return x;
}
void Union(int a,int b){
	int faa=findFather(a);
	int fab=findFather(b);
	if(faa!=fab)
		father[fab]=faa;
}
int estate_num[maxn],area[maxn],cnt_e[maxn]={},sum_a[maxn]={};
int person[maxn];
int main(){
	freopen("G:\\PATdata\\A1114.txt","r",stdin);
	cin>>n;
	init(n);
	int k;
	int dad,mom,son;
	for(int i=1;i<=n;i++){
		scanf("%d %d %d %d",&person[i],&dad,&mom,&k);
		if(family[person[i]]==0)
			family[person[i]]=i;
		int tmp=findFather(family[person[i]]);/////////
		//printf("%d\n",tmp);
		Union(i,tmp);
		shown[person[i]]=true;
		if(dad!=-1){
			if(family[dad]==0)
				family[dad]=i;
			Union(i,findFather(family[dad]));
			shown[dad]=true;
		}
		if(mom!=-1){
			if(family[mom]==0)
				family[mom]=i;
			Union(i,findFather(family[mom]));
			shown[mom]=true;
		}
		for(int j=0;j<k;j++){
			scanf("%d",&son);
			if(family[son]==0)
				family[son]=i;
			Union(i,findFather(family[son]));
			shown[son]=true;
		}
		scanf("%d %d",&estate_num[i],&area[i]);
	}

	for(int i=1;i<=n;i++){
		int tmp=family[person[i]];
		printf("%d\n",tmp);
		cnt_e[tmp]+=estate_num[i];
		sum_a[tmp]+=area[i];
	}

	int numfamily=0;
	for(int i=1;i<=maxn;i++){
		if(shown[i]==true)
			isroot[findFather(i)]++;
	}
	//sort(isroot+1,isroot+maxn+1);

	for(int i=1;i<=n;i++){
		if(isroot[i]!=0)
			numfamily++;
	}

	

	printf("¡£¡£¡£¡£Ê§°Ü´úÂë¡£%d\n",numfamily);

	/*for(int i=1;i<=numfamily;i++){
		printf("%d ",minid);

		printf("%d %d\n",setnum*1.0/isroot[i],sum_area*1.0/isroot[i]);
		
	}
	*/

	return 0;
}


