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
const int maxn=1e5+1;
struct Node{
	int addr,data,next;
	int order;
}node[maxn];
bool cmp(Node a,Node b){
	if(a.order==-1 || b.order==-1)
		return a.order>b.order;
	else
		return a.order<b.order;
}
int main(){
	int n,s,k;
	//freopen("G:\\PATdata\\A1074.txt","r",stdin);
	cin>>s>>n>>k;
	int addr;
for(int i=0;i<maxn;i++){
		node[i].order=-1;
	}
	for(int i=0;i<n;i++){
		cin>>addr;
		cin>>node[addr].data>>node[addr].next;
		node[addr].addr=addr;
	}
	
	int p=s,cnt=0;
	while(p!=-1){
		node[p].order=cnt++;
		p=node[p].next;
	}
	sort(node,node+maxn,cmp);
	n=cnt;
	for(int i=0;i<n/k;i++){
		for(int j=(i+1)*k-1;j>i*k;j--){
			printf("%05d %d %05d\n",node[j].addr,node[j].data,node[j-1].addr);
		}
		printf("%05d %d ",node[i*k].addr,node[i*k].data);
		if(i<n/k-1)
			printf("%05d\n",node[(i+1)*k+k-1].addr);
		else{
			if(n%k==0)
				printf("-1\n");
			else{
				printf("%05d\n",node[(i+1)*k].addr);
				for(int j=n/k*k;j<n;j++){
					printf("%05d %d ",node[j].addr,node[j].data);////////
					if(j<n-1)
						printf("%05d\n",node[j+1].addr);
					else
						printf("-1\n");
				}
			}
		}
	}
	return 0;
}