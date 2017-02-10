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
const int maxn=1000;
stack<int> st;
int arr[maxn];
int main(){
	int m,n,t;
		//freopen("G:\\PATdata\\A1051.txt","r",stdin);
	cin>>m>>n>>t;
	while(t--){
		while(!st.empty())
			st.pop();
		for(int i=1;i<=n;i++){
			cin>>arr[i];
		}
		int cur=1;
		bool flag=true;
		for(int i=1;i<=n;i++){
			st.push(i);///////////////////////////及以上两个for循环都是i<=n
			if(st.size()>m){
				flag=false;
				break;
			}
			while(!st.empty() && st.top()==arr[cur]){
				st.pop();
				cur++;
			}
		}
		if(st.empty()==true && flag==true)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}


	return 0;
}
