#include<iostream>
#include<string>
#include<map>
using namespace std;
const int maxn=2010;
const int INF=1e9;
map<int,string> int2str;
map<string,int> str2int;
map<string,int> gang;
int g[maxn][maxn]={0},weight[maxn]={0};
int n,k,numperson=0;
bool vis[maxn]={false};
void dfs(int now_v,int& head,int& num_m,int& total_v){/////////////////////////////////
	num_m++;
	vis[now_v]=true;
	if(weight[now_v]>weight[head])
		head=now_v;
	for(int i=0;i<numperson;i++){
		if(g[now_v][i]>0){////////////////////因为后来有路被访问过的，已为0 
			total_v+=g[now_v][i];
			g[now_v][i]=g[i][now_v]=0;//////////////
			if(vis[i]==false)
				dfs(i,head,num_m,total_v);
		}
	}
}
void dfs_travel(){
	for(int i=0;i<numperson;i++){
		if(vis[i]==false){
			int head=i,num_m=0,total_v=0;//////////////
			dfs(i,head,num_m,total_v);//////////////

			if(num_m>2 && total_v>k)
				gang[int2str[head]]=num_m;//////////////
		}
	}

}
int change(string str){
	if(str2int.find(str)!=str2int.end())
		return str2int[str];
	else{
		str2int[str]=numperson;
		int2str[numperson]=str;
		return numperson++;
	}
}
int main(){
	int w;
	string str1,str2;
//	freopen("G:\\PATdata\\A1034.txt","r",stdin);
	cin>>n>>k;//////////
	for(int i=0;i<n;i++){
		cin>>str1>>str2>>w;
		int id1=change(str1);
		int id2=change(str2);
		weight[id1]+=w;
		weight[id2]+=w;
		g[id1][id2]+=w;
		g[id2][id1]+=w;
	}
	dfs_travel();
	cout<<gang.size()<<endl;
	map<string,int>::iterator it;
	for(it=gang.begin();it!=gang.end();it++)
		cout<<it->first<<" "<<it->second<<endl;
	return 0;
}
