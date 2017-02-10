#include<cstdio>
#include<string>
#include<cctype>
using namespace std;
int main(){
	int a,b,c,p,q,r;
	freopen("G:\\PATdata\\A1058.txt","r",stdin);
	scanf("%d.%d.%d",&a,&b,&c);
	scanf("%d.%d.%d",&p,&q,&r);
	p+=a,q+=b,r+=c;
	if(r>=29){
		r-=29;
		q++;
	}
	if(q>=17){
		q-=17;
		p++;
	}
	printf("%d.%d.%d\n",p,q,r);
	return 0;
}