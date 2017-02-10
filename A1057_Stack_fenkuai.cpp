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
const int maxn=100010;
const int lim=317;
stack<int> st;
int bucket[lim]={},tb[maxn]={};
void peekMedian(){
	int k=st.size();
	if(k%2==1)
		k=(k+1)/2;
	else
		k=k/2;
	int sum=0,idx=0;
	for(idx=0;idx<lim;idx++){
		if(sum+bucket[idx]<k)
			sum+=bucket[idx];
		else
			break;
	}
	int b=idx*lim;
	while(1){
		sum+=tb[b];
		if(sum>=k){
			printf("%d\n",b);
			break;
		}
		b++;
	}
}
int n,a;
char str[20];
int main(){
	//freopen("G:\\PATdata\\A1057.txt","r",stdin);
	scanf("%d",&n);
	for(int k=0;k<n;k++){
		scanf("%s",str);
		if(strcmp(str,"Push")==0){
			scanf("%d",&a);
			st.push(a);
			bucket[a/lim]++;///////////////////////
			tb[a]++;		//////////////////////
		}else if(strcmp(str,"Pop")==0){
			if(!st.empty()){
				printf("%d\n",st.top());
				a=st.top();
				bucket[a/lim]--;///////////////
				tb[a]--;
				st.pop();

			}else{
				printf("Invalid\n");
			}
		}else{
			if(!st.empty()){
				peekMedian();
			}else{
				printf("Invalid\n");
			}
		}
	}
	return 0;
}