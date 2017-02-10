#include<cstdio>
#include<map>
#include<algorithm>
using namespace std;

int main(){
	int n,m;
	long long c;
	map<int,int> cnt;
	//freopen("G:\\PATdata\\A1054.txt","r",stdin);
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			scanf("%lld",&c);
			if(cnt.find(c)!=cnt.end())
				cnt[c]++;
			else
				cnt[c]=1;
		}
	}
	int k=0,max=0;
	for(map<int,int>::iterator it=cnt.begin();it!=cnt.end();it++){
		if(it->second>max){
			k=it->first;
			max=it->second;
		}
	}

	printf("%d\n",k);

	return 0;
}