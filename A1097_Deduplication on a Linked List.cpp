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
	int order;
}node[maxn];
bool isexit[2*maxn]={false};
bool cmp(NODE a,NODE b){
	return a.order<b.order;
}
int main(){
	int n,s;
	for(int i=0;i<maxn;i++){
		node[i].order=2*maxn;///////////////////////////////Îñ±Ø=2*maxn
	}
		//freopen("G:\\PATdata\\A1097.txt","r",stdin);
	cin>>s>>n;
	int addr;
		for(int i=0;i<n;i++){
			cin>>addr;
			cin>>node[addr].key>>node[addr].next;
			node[addr].addr=addr;
		}
		int cntvalid=0,cntremoved=0,p=s;
		while(p!=-1){
			if(!isexit[abs(node[p].key)]){
				isexit[abs(node[p].key)]=true;
				node[p].order=cntvalid++;
			}else{
				node[p].order=maxn+cntremoved++;
		
			}
			p=node[p].next;
		}


	if(cntvalid!=0){
			sort(node,node+maxn,cmp);
		int cnt=cntvalid+cntremoved;
			for(int i=0;i<cnt;i++){
				if(i!=cntvalid-1 && i!=cnt-1)
					printf("%05d %d %05d\n",node[i].addr,node[i].key,node[i+1].addr);///////////////
				else
					printf("%05d %d -1\n",node[i].addr,node[i].key);
			}

	}
	return 0;
}