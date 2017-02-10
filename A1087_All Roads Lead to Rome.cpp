//A1087    All Roads Lead to Rome  //19:16
#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<map>
#include<vector>
using namespace std;
const int maxn=220,inf=1e9;
int g[maxn][maxn],d[maxn],w[maxn],weight[maxn],num[maxn];
int n,k;
bool vis[maxn]={false};
vector<int> pre[maxn],tmp,ans;
map<string,int> str2num;
//string num2str[maxn];
map<int, string> num2str;
void dijk(int s){
	fill(d,d+maxn,inf);
	d[s]=0;
	fill(num,num+maxn,0);
	num[s]=1;
	for(int i=0;i<n;i++){
		pre[i].push_back(i);
	}
	for(int i=0;i<n;i++){
		int u=-1,min=inf;
		for(int j=0;j<n;j++){
			if(d[j]<min && vis[j]==false)
			{
				u=j;
				min=d[j];
			}
		}
		if(u==-1)
			return;
		vis[u]=true;
		for(int v=0;v<n;v++){
			if(vis[v]==false && g[u][v]!=inf){
				if(d[u]+g[u][v]<d[v]){
					d[v]=d[u]+g[u][v];
					pre[v].clear();
					pre[v].push_back(u);
					num[v]=num[u];
				}else if(d[u]+g[u][v]==d[v]){
					pre[v].push_back(u);
					num[v]+=num[u];
				}
			}
		}
	}
}
int numpath=0;
int maxweight=0,avgmaxweight=0;
void dfs(int v){
	if(v==0){
		tmp.push_back(v);
		numpath++;
		int wei=0;////////////////////
		for(int i=tmp.size()-2;i>=0;i--){////////////////////
			int id=tmp[i];
			wei+=weight[id];
			//avgmaxweight+=1.0*weight[id]/tmp.size();
		}
		double avgmwei=wei*1.0/(tmp.size()-1);
		//cout<<avgmwei<<endl;
		if(wei>maxweight){
			maxweight=wei;
			avgmaxweight=avgmwei;
			ans=tmp;
		}else if(avgmwei>avgmaxweight && maxweight==wei){
			avgmaxweight=avgmwei;	
			ans=tmp;
		}
		tmp.pop_back();
		return;
	}
	tmp.push_back(v);
	for(int i=0;i<pre[v].size();i++){
		dfs(pre[v][i]);
	}
	tmp.pop_back();
}
int main(){
	string st;
	freopen("G:\\PATdata\\A1087.txt","r",stdin);
	cin>>n>>k>>st;
	fill(g[0],g[0]+maxn*maxn,inf);
	str2num[st]=0;
	num2str[0]=st;
	string city;
	for(int i=1;i<=n-1;i++){
		cin>>city;
		str2num[city]=i;
		num2str[i]=city;
		cin>>weight[i];
	}
	weight[0]=0;
	string c1,c2;
	int u=0,v=0;
	for(int i=1;i<=k;i++){
		cin>>c1>>c2;
		u=str2num[c1];
		v=str2num[c2];///////////////
		cin>>g[u][v];
		g[v][u]=g[u][v];
	}
	dijk(0);
	int rom=str2num["ROM"];///////////////////////////////////坑点！！！！，rom不一定为1
	dfs(rom);
	//avgmaxweight=(int)(maxweight/(ans.size()-1));
	cout<<numpath<<" "<<d[rom]<<" "<<maxweight<<" "<<(int)avgmaxweight<<endl;////////num[rom]也可 
	for(int i=ans.size()-1;i>=0;i--){
		cout<<num2str[ans[i]];
		if(i>0)
			cout<<"->";
	}

	return 0;
}
