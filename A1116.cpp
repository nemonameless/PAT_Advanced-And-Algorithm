#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<cctype>
#include<algorithm>
#include<cmath>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<stack>
using namespace std;
const int maxn=10100;
struct STU{
	int id;
	int rk;
	bool vis,inq;
}stu[maxn];
bool isprime(int n){
	if(n<=1)
		return false;
	int sqr=(int)sqrt(1.0*n);
	for(int i=2;i<=sqr;i++){
		if(n%i==0)
			return false;
	}
	return true;
}
int main(){
	int n;
	//freopen("G:\\PATdata\\A1116.txt","r",stdin);
	scanf("%d",&n);
	int id;
	for(int i=0;i<n;i++){
		scanf("%d",&id);
		stu[id].rk=i+1;
		stu[id].inq=true;
	}
	int q;
	scanf("%d",&q);
	for(int i=0;i<q;i++){
		scanf("%d",&id);
		if(stu[id].inq==false){
			printf("%04d: Are you kidding?\n",id);
		}else{
			if(stu[id].vis==true){
				printf("%04d: Checked\n",id);
			}else{
				if(stu[id].rk==1){
					printf("%04d: Mystery Award\n",id);
				}else if(isprime(stu[id].rk)){
					printf("%04d: Minion\n",id);
				}else{
					printf("%04d: Chocolate\n",id);
				}
				stu[id].vis=true;
			}
		}
	}
	return 0;
}