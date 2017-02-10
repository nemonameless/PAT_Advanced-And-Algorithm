#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<queue>
#include<cmath>
using namespace std;
const int maxn=510,inf=1e9;
bool vis[maxn]={false};
int d[maxn],w[maxn],weight[maxn],g[maxn][maxn],num[maxn];
vector<int> tmp,ans,pre[maxn];
int n,m,L,k,s,t;    
void dijk(int s){
	fill(d,d+maxn,inf);
	d[s]=0;
	fill(num,num+maxn,0);
	num[s]=1;
	for(int i=0;i<=n;i++){
		pre[i].push_back(i);
	}
	for(int i=0;i<n;i++){////////////////////////i<n
		int u=-1,min=inf;
		for(int j=0;j<=n;j++){
			if(vis[j]==false && d[j]<min){
				u=j;
				min=d[j];
			}
		}
		if(u==-1)
			return;
		vis[u]=true;
		for(int v=0;v<=n;v++){//////////////////////////////
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
int maxfushe=-1,min_half_fushe=inf; ////////////////////
void dfs(int v){
	if(v==s){
		tmp.push_back(v);
		int fushe=0,half_fushe=0;
		for(int i=tmp.size()-1;i>=0;i--){
			int id=tmp[i];
			//cout<<id<<".";
			fushe+=weight[id];
			//if(tmp.size()%2==1){
				if(i<(int)(tmp.size()/2))
					half_fushe+=weight[id];
		}
	///	cout<<fushe<<" "<<half_fushe<<endl;
		if(fushe%k > maxfushe){
			maxfushe=fushe%k;
			min_half_fushe=half_fushe;
			ans=tmp;
		}else if(fushe==maxfushe && half_fushe < min_half_fushe){
			min_half_fushe=half_fushe;
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

struct Node {
    int id;         //结点编号
    int layer;      //结点层号
};
bool inq[maxn]={false};
void BFS() {
    queue<Node> q;
    Node start;
    start.id = s;
    start.layer = 0;
    q.push(start);    // 起点入队
    inq[start.id] = true;
    while(!q.empty()) {
        Node topNode = q.front();
        q.pop();
        int u = topNode.id;
        if(topNode.layer < L) {    // 计算点权增长
            weight[u] += (int)(ceil(weight[u] * 1.0 * (L - topNode.layer) / L) + 0.5);
        }
        for(int v = 0; v < n; v++) {
            if(!inq[v] && g[u][v] != inf) {
                Node next;
                next.id = v;
                next.layer = topNode.layer + 1;    // 层号计算
                q.push(next);
                inq[next.id] = true;
            }
        }
    }
}

int main(){
//	freopen("G:\\PATdata\\codeup_heianqixi.txt","r",stdin);
	cin>>n>>m>>L>>k>>s>>t;
	fill(g[0],g[0]+maxn*maxn,inf);//////////
	for(int i=0;i<n;i++){
		cin>>weight[i];
	}
	int u,v;
	for(int i=0;i<m;i++){
		cin>>u>>v;
		cin>>g[u][v];
		g[v][u]=g[u][v];
	}
	BFS();
	if(!inq[t]) {
        printf("-1\n");
        return 0;
    }
	dijk(s);
	

	
		dfs(t);
		

		cout<<num[t]<<" "<<d[t]<<" "<<maxfushe<<" "<<min_half_fushe<<endl;;
		for(int i=ans.size()-1;i>=0;i--){
			cout<<ans[i];
			if(i>0)
				cout<<"->";
		}
	
	return 0;
}
