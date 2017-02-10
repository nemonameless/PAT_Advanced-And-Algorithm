#include<cstdio>
#include<set>
using namespace std;
const int maxn=51;
set<int> st[maxn];
void compare(int x,int y){
	int samenum=0,totalnum=st[y].size();//////////////////
	for(set<int>::iterator it=st[x].begin();it!=st[x].end();it++){
		if(st[y].find(*it)!=st[y].end())
			samenum++;
		else
			totalnum++;
	}
	printf("%.1f%%\n",samenum*100.0/totalnum);
}

int main(){
	int n,m,q,st1,st2,v;
	///freopen("G:\\PATdata\\A1063.txt","r",stdin);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&m);
		for(int j=0;j<m;j++){
			scanf("%d",&v);
			st[i].insert(v);
		}
	}
	scanf("%d",&q);
	for(int i=0;i<q;i++){
		scanf("%d%d",&st1,&st2);
		compare(st1,st2);
	}

	return 0;
}