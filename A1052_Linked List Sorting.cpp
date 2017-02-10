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
const int maxn=100001;
struct NODE{
	int addr,key,next;
	bool fg;
}node[maxn];
bool cmp(NODE a,NODE b){
	if(a.fg==false || b.fg==false)
		return a.fg>b.fg;
	else
		return a.key<b.key;
}
int main(){
	int n,s;
	for(int i=0;i<maxn;i++){
			node[i].fg=false;;
		}
	//	freopen("G:\\PATdata\\A1052.txt","r",stdin);
	cin>>n>>s;
	int addr;
		for(int i=0;i<n;i++){

			cin>>addr;
			cin>>node[addr].key>>node[addr].next;
			node[addr].addr=addr;
		}
		int cnt=0,p=s;
		while(p!=-1){
			node[p].fg=true;
			cnt++;
			p=node[p].next;
		}


	if(cnt!=0){
			sort(node,node+maxn,cmp);
			s=node[0].addr;
			printf("%d %05d\n",cnt,s);
			for(int i=0;i<cnt;i++){
				if(i<cnt-1)
					printf("%05d %d %05d\n",node[i].addr,node[i].key,node[i+1].addr);///////////////
				else
					printf("%05d %d -1\n",node[i].addr,node[i].key);
			}

	}else
		printf("0 -1\n");

	return 0;
}