#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdio>
using namespace std;
const int maxn=100;
int main(){
	double sum=1.0;
	double w,t,l;
	for(int i=0;i<3;i++){
		cin>>w>>t>>l;
		if(w>=t && w>=l){
				sum*=w;
				printf("W ");
		}
		if(t>=w && t>=l){
			sum*=t;
		printf("T ");
		}
		if(l>=t && l>=w){
			sum*=l;
		printf("L ");
		}
	}
	sum=(sum*0.65-1)*2.0;
	printf("%.2lf\n",sum);
	return 0;
}
//这都能过？？？
