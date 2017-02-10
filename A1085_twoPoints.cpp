#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
const int maxn=100010;
int a[maxn];
int n,p;
int main(){
	freopen("G://PATdata//A1085.txt","r",stdin);
	scanf("%d%d", &n, &p);
    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    sort(a, a + n);
	int cnt=1;/////////////////////////////// 
	int i=0,j=0;
	while(i<n){
		while(j<n && a[j]<=(long long)a[i]*p){//////long long最后一点2分 
			cnt=max(cnt,j-i+1);
			j++;
		}
		i++;
	}
	printf("%d\n",cnt);
	
	/*超时且还有一点未过，21分
	for(int i=0;i<n-1;i++){
		int cnt=1;
		int j=i+1;
		while((long long)a[i]*p>=a[j] && j<n){
			cnt++;
			j++;
		}
		//printf("%d\n",cnt);
		ccnt[i]=cnt;
	}
//	printf("%d\n",cnt);
	sort(ccnt,ccnt+n,cmp);
	printf("%d\n",ccnt[0]);
	*/
	
	return 0;
}
