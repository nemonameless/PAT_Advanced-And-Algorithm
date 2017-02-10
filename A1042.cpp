#include<cstdio>
using namespace std;
const int n=54;
int start[n],stop[n],next[n];
char mp[5]={'S','H','C','D','J'};
int main(){
	int k;
	freopen("G:\\PATdata\\A1042.txt","r",stdin);
	scanf("%d",&k);
	for(int i=1;i<=n;i++){
		start[i]=i;
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&next[i]);
	}
	while(k--){
		for(int i=1;i<=n;i++){        //错把n写成k
			stop[next[i]]=start[i]; //把1号牌存在stop[36]中，2号牌存在stop[52]中，，，
		}
		for(int i=1;i<=n;i++){
			start[i]=stop[i];//新的牌的排列，供下次洗牌用
		}
	}
	for(int i=1;i<=n;i++){
		if(i!=1)
			printf(" ");
		start[i]--;
		printf("%c%d",mp[start[i]/13],start[i]%13+1);
	}

	return 0;
}