#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=1010;
int toll[25];
struct Record{
	char name[25];
	int month,dd,hh,mm;
	bool status;
}rec[maxn],tmp;
bool cmp(Record a,Record b){
	int s=strcmp(a.name,b.name);
	if(s!=0)
		return s<0;
	else if(a.month!=b.month)
		return a.month <b.month;
	else if(a.dd!=b.dd)
		return a.dd<b.dd;
	else if(a.hh!=b.hh)
		return a.hh<b.hh;
	else 
		return a.mm<b.mm;
}
void get_ans(int on,int off,int &time,int &money){
	tmp=rec[on];
	while(tmp.dd<rec[off].dd || tmp.mm<rec[off].mm || tmp.hh<rec[off].hh){
		time++;
		money+=toll[tmp.hh];
		tmp.mm++;
		if(tmp.mm>=60){
			tmp.mm=0;
			tmp.hh++;
		}
		if(tmp.hh>=24){///////////////24¶ø²»ÊÇ60
			tmp.hh=0;
			tmp.dd++;
		}
	}
}
int main(){
	freopen("G:\\PATdata\\A1016.txt","r",stdin);
	for(int i=0;i<24;i++){
		scanf("%d",&toll[i]);
	}
	int n;
	scanf("%d",&n);
	char line[10];
	for(int i=0;i<n;i++){
		scanf("%s", rec[i].name);
        scanf("%d:%d:%d:%d", &rec[i].month, &rec[i].dd, &rec[i].hh, &rec[i].mm);
		scanf("%s",line);
		if(strcmp(line,"on-line")==0){
			rec[i].status=true;
		}else{
			rec[i].status=false;
		}
	}
	sort(rec,rec+n,cmp);
	int on=0,off,next;
	while(on<n){
		int needprint=0;
		next=on;
		while(next<n && strcmp(rec[next].name,rec[on].name)==0){
			if(needprint ==0 && rec[next].status==true)
				needprint=1;
			else if(needprint ==1 && rec[next].status==false)
				needprint=2;
			next++;
		}
		if(needprint<2){
			on=next;
			continue;
		}
		int Allmoney=0;
		printf("%s %02d\n",rec[on].name,rec[on].month);
		while(on<next){
			while(on <next-1 && !(rec[on].status==true && rec[on+1].status==false))
				on++;
			off=on+1;
			if(off==next){
				on=next;
				break;
			}
			printf("%02d:%02d:%02d ",rec[on].dd,rec[on].hh,rec[on].mm);
			printf("%02d:%02d:%02d ",rec[off].dd,rec[off].hh,rec[off].mm);
			int time=0,money=0;
			get_ans(on,off,time,money);
			Allmoney+=money;
			printf("%d $%.2f\n",time,money*1.0/100.0);
			on=off+1;
		}
		printf("Total amount: $%.2f\n",Allmoney*1.0/100.0);
	}
	return 0;
}


