#include<cstdio>
#include<iostream>
using namespace std;

int main(){
	int n,up=0,down=0,now[101]={};
	cin>>n;
	now[0]=0;
	for(int i=1;i<=n;i++){
		cin>>now[i];
		if(now[i]>now[i-1])
			up+=(now[i]-now[i-1]);
		if(now[i]<now[i-1])
			down+=-(now[i]-now[i-1]);
	}
	printf("%d\n",up*6+down*4+n*5);
	return 0;
}