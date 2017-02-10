#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
const int maxn = 10000+1;
string a[maxn];
bool cmp(string a,string b){
	return a+b<b+a;
}
int main() {
    int n;
	//freopen("G:\\PATdata\\A1038.txt","r",stdin);
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
       cin>>a[i];
    }
	sort(a,a+n,cmp);
	string ans;
	for(int i = 0; i < n; i++) {
       ans+=a[i];
    }
	while(ans.size()!=0 && ans[0]=='0'){
		ans.erase(ans.begin());
	}
	if(ans.size()==0)
		cout<<0;
	else
		cout<<ans;
	return 0;
}