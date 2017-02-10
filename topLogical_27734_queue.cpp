#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
const int maxn = 1010;
int n, m,inDegree[maxn]={0};
vector<int> g[maxn],topOrder;
int topologicalSort() {
    int num = 0;    //记录加入拓扑序列的顶点数
    priority_queue<int, vector<int>, greater<int> > q;    // 小顶堆的优先队列
    for(int i = 0; i < n; i++) {
        if(inDegree[i] == 0) {
            q.push(i);      //将所有入度为0的顶点入队
        }
    }
    while(!q.empty()) {
        int u = q.top();      //取队首顶点u
        topOrder.push_back(u);
        q.pop();
        for(int i = 0; i < g[u].size(); i++) {
            int v = g[u][i];     //u的后继结点v
            inDegree[v]--;           //顶点v的入度减1
            if(inDegree[v] == 0) {   //顶点v的入度减为0则入队
                q.push(v);
            }
        }
        g[u].clear();   //清空顶点u的所有出边（如无必要可不写）
        num++;              //加入拓扑序列的顶点数加1
    }
    return num;
}
int main(){
	//freopen("G:\\PATdata\\codeup27734_topLogical.txt","r",stdin);
    scanf("%d%d", &n, &m);
    for(int i = 0; i < m; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        inDegree[v]++;    // 累计入度
        g[u].push_back(v);    // 建边
    }
    int num = topologicalSort();    // 拓扑排序
    if(num == n) {
        printf("YES\n");
        for(int i = 0; i < n; i++) {
            printf("%d", topOrder[i]);
            if(i < n - 1) printf(" ");
            else printf("\n");
        }
    } else {
        printf("NO\n%d\n", n - num);    // 无法消灭的个数
    }
    return 0;
}