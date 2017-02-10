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
bool isprime(int n) {
    if(n <= 1) return false;
    int sqr = (int)sqrt(1.0 * n);
    for(int i = 2; i <= sqr; i++) {
        if(n % i == 0) return false;
    }
    return true;
}
int d[120];
int main(){
	int n,radix;
		//freopen("G:\\PATdata\\A1015.txt","r",stdin);
		
	while(cin>>n ){
		if(n<0)
			break;
		cin>>radix;
		if(isprime(n)==false)
			cout<<"No"<<endl;
		else{
		int len=0;
			do{
				d[len++]=n%radix;
				n/=radix;
			}while(n!=0);
			int n2=0;
			for(int i=0;i<len;i++){
				n2=n2*radix+d[i];
			}

			if(isprime(n2))
				cout<<"Yes"<<endl;	
			else
				cout<<"No"<<endl;	
		}
	}
	return 0;
}