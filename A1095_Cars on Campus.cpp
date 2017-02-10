#include<cstdio>
#include<string>
#include<map>
#include<cstring>
#include<algorithm>
using namespace std;
struct Car{
	char id[9];
	int hh,mm,ss;
	bool status;
	int time_sum;
}car[10010],valid[10010];
bool cmpByIdAndTime(Car a,Car b){
	int s=strcmp(a.id,b.id);
	if(s!=0)
		return strcmp(a.id,b.id)<0;
	else if(a.hh!=b.hh)
		return a.hh<b.hh;
	else if(a.mm!=b.mm)
		return a.mm<b.mm;
	else 
		return a.ss<b.ss;
}
bool cmpByTime(Car a,Car b){
	return a.time_sum<b.time_sum;
}
int get_time(int hh,int mm,int ss){
	return hh*3600+mm*60+ss;
}
map<string,int> parkTime;
int main(){
	int n,k;
	char line[5];///////////////
	freopen("G:\\PATdata\\A1095.txt","r",stdin);
	scanf("%d%d",&n,&k);
	for(int i=0;i<n;i++){
		scanf("%s %d:%d:%d",car[i].id, &car[i].hh, &car[i].mm, &car[i].ss);
		scanf("%s", line);
		if(strcmp(line,"in")==0)
			car[i].status=true;
		else
			car[i].status=false;
		car[i].time_sum=get_time(car[i].hh,car[i].mm,car[i].ss);
	}
	sort(car,car+n,cmpByIdAndTime);
	int maxtime=-1,num=0;;
	for(int i=0;i<n-1;i++){
		if(strcmp(car[i].id,car[i+1].id)==0 && car[i].status==true && car[i+1].status==false){
			valid[num++]=car[i];
			valid[num++]=car[i+1];
			int inTime=car[i+1].time_sum-car[i].time_sum;

			if(parkTime.count(car[i].id)==0){////////////map中没有这个车牌，则置0
				parkTime[car[i].id]=0;
			}
			parkTime[car[i].id]+=inTime;
			maxtime=max(parkTime[car[i].id],maxtime);
		}
	}
	sort(valid,valid+num,cmpByTime);
	int now=0,numcar=0;
	int h,m,s;
	for(int j=0;j<k;j++){
		scanf("%d:%d:%d",&h,&m,&s);
		int time=get_time(h,m,s);
		for(;(now<num )&& (valid[now].time_sum<=time);now++){	//要for循环就不能限定now的初值,或者用while 
			if(valid[now].status==true)//////////////////valid而不是car
				numcar++;
			else
				numcar--;
		//	now++;
		}
		printf("%d\n",numcar);
	}
	map<string,int>::iterator it;
	for(it=parkTime.begin();it!=parkTime.end();it++){
		if(it->second==maxtime)
			printf("%s ",it->first.c_str());
	
	}
	printf("%02d:%02d:%02d\n",maxtime/3600,maxtime%3600/60,maxtime%60);
	return 0;
}

