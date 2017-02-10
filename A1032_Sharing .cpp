#include<cstdio>
#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
const int maxn=100001;
struct node{
	int next;
	char data;
	bool fg;
}nd[maxn];
int main(){
	freopen("G:\\PATdata\\A1032.txt","r",stdin);

	for(int i=0;i<maxn;i++){
		nd[i].fg=false;
	}
	int s1,s2,n;
	cin>>s1>>s2>>n;
	int addr,next;
	char data;
	for(int i=0;i<n;i++){
		cin>>addr>>data>>next;
		nd[addr].data=data;
		nd[addr].next=next;
	}
	int p;
	for(p=s1;p!=-1;p=nd[p].next){
		nd[p].fg=true;
	}
	for(p=s2;p!=-1;p=nd[p].next){
		if(nd[p].fg==true)
			break;
	}
	if(p!=-1)
		printf("%05d\n",p);
	else
		printf("-1\n");

	return 0;
}
