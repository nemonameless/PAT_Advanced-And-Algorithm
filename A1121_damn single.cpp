#include<cstdio>
#include<cstring>
#include<set>
#include<algorithm>
using namespace std;
const int maxn=99999+1;
const int maxm=50001;
struct CP{
	int single;
	int id;
	int isvisit;
}cp[maxn];

int namelist[maxm];
int main(){
	int n,m;
	//freopen("G:\\PATdata\\A1121.txt","r",stdin);
	scanf("%d",&n);
	for(int i=0;i<maxn;i++){
		cp[i].single=0;
		cp[i].id=-1;
		cp[i].isvisit=0;
	}

	int name1,name2;
	for(int i=0;i<n;i++){
		scanf("%d %d",&name1,&name2);
		cp[name1].id=i;
		cp[name2].id=i;
		cp[name1].single=2;
		cp[name2].single=2;
	}
	scanf("%d",&m);
	for(int i=0;i<m;i++){
		scanf("%d",&namelist[i]);
	}
	int signum=0;
	sort(namelist,namelist+m);
	for(int i=0;i<m;i++){
		if(cp[namelist[i]].single==0)
			signum++;
		if(cp[namelist[i]].single==2 && cp[namelist[i]].isvisit==0){
			//int j=0;
			int flag=1;
			for(int j=i+1;j<m;j++){
				if(cp[namelist[j]].id == cp[namelist[i]].id ){
					flag=0;
					cp[namelist[j]].isvisit=1; 
					break;
				}
			}
			if(flag==1){
				signum++;
				cp[namelist[i]].single=1;
			}
		}
	}
	printf("%d\n",signum);
	if(signum!=0){
		int num=0;
		for(int i=0;i<m;i++){	
			if(cp[namelist[i]].single!=2){
				printf("%05d",namelist[i]);////////////////
				num++;
				if(num<signum)
					printf(" ");
			}
		
		}
	}

	return 0;
}