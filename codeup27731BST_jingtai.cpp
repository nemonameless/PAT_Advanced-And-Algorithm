#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
const int maxn = 40;
struct node {    // 二叉树静态写法
    int data;
    int lchild;
    int rchild;
} Node[maxn * 2];
int n, data1[maxn], data2[maxn];    // data1跟data2存放插入序列
int num = 0;    // 已有结点个数
int newNode(int x) {    // 分配结点
    Node[num].data = x;
    Node[num].lchild = -1;
    Node[num].rchild = -1;
    return num++;
}
void insert(int &root, int x) {    // 插入x
    if(root == -1) {
        root = newNode(x);    // 查询失败，在此处插入
        return;
    }
    if(x < Node[root].data) {    // 往左子树插
        insert(Node[root].lchild, x);
    } else {    // 往右子树插
        insert(Node[root].rchild, x);
    }
}
int Create(int data[]) {    // 建树
    int root = -1;
    for(int i = 0; i < n; i++) {
        insert(root, data[i]);
    }
    return root;
}
// 两棵树的先序，第一棵的后序、层序，以下全是模板
vector<int> pre1, pre2, post, layer;
void preOrder(vector<int> &pre, int root) {
    if(root == -1) {
        return;
    }
    pre.push_back(Node[root].data);
    preOrder(pre, Node[root].lchild);
    preOrder(pre, Node[root].rchild);
}
void postOrder(int root) {
    if(root == -1) {
        return;
    }
    postOrder(Node[root].lchild);
    postOrder(Node[root].rchild);
    post.push_back(Node[root].data);
}
void layerOrder(int root) {
    queue<int> q;
    q.push(root);
    while(!q.empty()) {
        int now = q.front();
        q.pop();
        layer.push_back(Node[now].data);
        if(Node[now].lchild != -1) q.push(Node[now].lchild);
        if(Node[now].rchild != -1) q.push(Node[now].rchild);
    }
}
int main() {
//    freopen("4.in", "r", stdin);
//    freopen("4.out", "w", stdout);
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &data1[i]);    // 第一个排列
    }
    int root1 = Create(data1);
    for(int i = 0; i < n; i++) {
        scanf("%d", &data2[i]);    // 第二个排列
    }
    int root2 = Create(data2);
    preOrder(pre1, root1);    // 第一棵先序
    preOrder(pre2, root2);    // 第二棵先序
    bool flag = true;
    for(int i = 0; i < n; i++) {
        if(pre1[i] != pre2[i]) {    // 判断先序是否有不同
            flag = false;
            break;
        }
    }
    if(flag) printf("YES\n");    // 是同一棵
    else printf("NO\n");    // 不是同一棵
    postOrder(root1);    // 后序
    layerOrder(root1);    // 层序
    for(int i = 0; i < n; i++) {    // 输出
        printf("%d", post[i]);
        if(i < n - 1) printf(" ");
        else printf("\n");
    }
    for(int i = 0; i < n; i++) {
        printf("%d", layer[i]);
        if(i < n - 1) printf(" ");
        else printf("\n");
    }
    return 0;
}
