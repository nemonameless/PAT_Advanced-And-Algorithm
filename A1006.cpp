#include<cstdio>
struct person{
	char id[20];/////////至少15，否则最后一点扣6分   //比B1028还简单点
	int ih,im,is;
	int oh,om,os;
}man[15],tmp,earlist,latest;
void init(){
	earlist.ih=23,earlist.im=59,earlist.is=59;
	latest.oh=0,latest.om=0,latest.os=0;
}
bool more(person a,person b){
	if(a.oh!=b.oh )
		return a.oh>=b.oh;
	else if(a.om !=b.om)
		return a.om>=b.om;
	else 
		return a.os>=b.os;
}
bool less(person a,person b){
	if(a.ih!=b.ih )
		return a.ih<=b.ih;
	else if(a.im !=b.im)
		return a.im<=b.im;
	else 
		return a.is<=b.is;
}
int main(){
	int n,cnt=0;
	freopen("G:\\PATdata\\A1006.txt","r",stdin);
	scanf("%d",&n);
	init();
	for(int i=0;i<n;i++){
		scanf("%s %d:%d:%d %d:%d:%d",tmp.id,&tmp.ih,&tmp.im,&tmp.is,&tmp.oh,&tmp.om,&tmp.os);
		if(more(tmp,latest))
				latest=tmp;
		if(less(tmp,earlist))
				earlist=tmp;
	}
	printf("%s %s",earlist.id ,latest.id );

	return 0;
}