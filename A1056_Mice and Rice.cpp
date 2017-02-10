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
const int maxn=1010;
struct mice{
	int weight,r;
}mice[maxn];
int main(){
	int np,ng,order;
	//freopen("G:\\PATdata\\A1056.txt","r",stdin);
	cin>>np>>ng;
	for(int i=0;i<np;i++){
		cin>>mice[i].weight;
	}
	queue<int> q;
	for(int i=0;i<np;i++){
		cin>>order;
		q.push(order);
	}
	int tmp=np,group;
	while(q.size()!=1){
		if(tmp%ng==0)
			group=tmp/ng;
		else
			group=tmp/ng+1;
		for(int i=0;i<group;i++){
			int k=q.front();
			for(int j=0;j<ng;j++){
				if(i*ng+j>=tmp)
					break;
				int front=q.front();
				if(mice[front].weight>mice[k].weight){
					k=front;
				}
				mice[front].r=group+1;
				q.pop();
			}
			q.push(k);
		}
		tmp=group;
	}
	mice[q.front()].r=1;
	for(int i=0;i<np;i++){
		cout<<mice[i].r;
		if(i<np-1)
			cout<<" ";
	}
		
	return 0;
}