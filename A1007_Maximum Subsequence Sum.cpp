#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
const int maxn=10010;
int a[maxn],dp[maxn];
int s[maxn]={};
int main(){
	int n;
	freopen("G:\\PATdata\\A1007.txt","r",stdin);
	cin>>n;
	bool flag=false;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i]>=0)///////////////
			flag=true;
	}
	if(flag==false){
		cout<<"0 "<<a[0]<<" "<<a[n-1]<<endl;
		return 0;
	}
	dp[0]=a[0];
	for(int i=1;i<n;i++){
		if(dp[i-1]+a[i]>a[i]){
			dp[i]=dp[i-1]+a[i];
			s[i]=s[i-1];
		}else{
			dp[i]=a[i];
			s[i]=i;
		}
	}
	int k=0;
	for(int i=1;i<n;i++){
		if(dp[i]>dp[k])
			k=i;
	}
	cout<<dp[k]<<" "<<a[s[k]]<<" "<<a[k]<<endl;
	return 0;
}

