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
const int maxn=111,inf=1e9;
struct Customer{
	int cometime,servetime;
}newCustomer;
vector<Customer> custom;
int changeTime(int h,int m,int s){
	return h*3600+m*60+s;
}
bool cmp(Customer a,Customer b){
	return a.cometime<b.cometime;
}
int endTime[111];
int main(){
	int c,w,totTime=0;
	//freopen("G:\\PATdata\\A1017.txt","r",stdin);
	cin>>c>>w;
	int stTime=changeTime(8,0,0);
	int edTime=changeTime(17,0,0);
	for(int i=0;i<w;i++)
		endTime[i]=stTime;///////////i号窗口的当前服务结束时间 初始化为stTime
	for(int i=0;i<c;i++){
		int h,m,s,serverTime;
		scanf("%d:%d:%d %d",&h,&m,&s,&serverTime);
		int comeTime=changeTime(h,m,s);
		if(comeTime>edTime)  /////////超过17：00:00后来的不算
			continue;
		newCustomer.cometime=comeTime;
		newCustomer.servetime= serverTime<=60?serverTime*60:3600;////////////
		custom.push_back(newCustomer);
	}
	sort(custom.begin(),custom.end(),cmp);//////////按到达时间先后
	for(int i=0;i<custom.size();i++){
		int idx=-1,minEndTime=inf;
		for(int j=0;j<w;j++){       //////////一个个窗口循环
			if(endTime[j]<minEndTime){//////////选择当前最早服务结束的窗口，编号为idx
				minEndTime=endTime[j];
				idx=j;
			}
		}
		if(endTime[idx]<=custom[i].cometime) ///////custom[i]在窗口空闲之后才来，则直接接受服务
			endTime[idx]=custom[i].cometime+custom[i].servetime;
		else{
			totTime+=(endTime[idx]-custom[i].cometime);///////custom[i]来的太早，须等待
			endTime[idx]+=custom[i].servetime;
		}
	}
	if(custom.size()==0)
		printf("0.0");
	else
		printf("%.1f",totTime*1.0/60/custom.size());

	return 0;
}