#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct bign{
	int d[1000];/////////////////
	int len;
	bign(){
		memset(d,0,sizeof(d));
		len=0;
	}
};
bign change(char str[]){
	bign a;
	a.len=strlen(str);
	for(int i=0;i<a.len;i++){
		a.d[i]=str[a.len-1-i]-'0';//////////////
	}
	return a;
}

bign add(bign a,bign b){
	bign c;
	int carry=0;
	for(int i=0;i<max(a.len,b.len);i++){
		int tmp=a.d[i]+b.d[i]+carry;
		c.d[c.len++]=tmp%10;////////////////
		carry=tmp/10;
	}
	if(carry!=0)
		c.d[c.len++]=carry;////////
	return c;
}
bool judge(bign a){
	for(int i=0;i<=a.len/2;i++){//////////////////
		if(a.d[i]!=a.d[a.len-1-i])
			return false;
	}
	return true;
}
void print(bign a){
	for(int i=a.len-1;i>=0;i--){
		printf("%d",a.d[i]);
		if(i==0)
			printf("\n");
	}
}
int main(){
	char str[1000];
	int n;
	//freopen("G:\\PATdata\\A1024.txt","r",stdin);
	while(scanf("%s %d",str,&n)!=EOF){
		bign a=change(str);
		int cnt=0;
		while(cnt<n && judge(a)==false){
			bign b=a;
			reverse(b.d,b.d+b.len);
			//printf("%d %d*",b.d[0],b.len);
			a=add(a,b);
			cnt++;
		}
		print(a);
		printf("%d\n",cnt);
	}
    return 0;
}

