//paste.ubuntu.com/15334524/
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
const int maxn = 50;
const int INF = 0x3fffffff;
struct node {
    int data;
    int lchild;
    int rchild;
}Node[maxn];
int in[maxn];    //中序
vector<int> pre, post;
int num = 0;    // 已分配的结点个数
int newNode(int x) {    // 分配结点
    Node[num].data = x;
    Node[num].lchild = Node[num].rchild = -1;    // -1表示NULL
    return num++;
}
//当前二叉树的层序序列为layer，中序序列区间为[inL, inR]
//create函数返回构建出的二叉树的根结点地址
int create(vector<int> layer, int inL, int inR) {
    if(layer.size() == 0) {
        return -1;
    }
    int root = newNode(layer[0]);  //新建一个新的结点，用来存放当前二叉树的根结点
    int k;
    for(k = inL; k <= inR; k++) {    // 在中序中找根结点
        if(in[k] == layer[0]) {
            break;
        }
    }
    vector<int> layerLeft;    // 左子树层序
    vector<int> layerRight;    // 右右子树层序
    for(int i = 1; i < layer.size(); i++) {    // 剩余所有元素
        bool isLeft = false;    // 是否在左子树
        for(int j = inL; j < k; j++) {    // 在中序中找layer[i]
            if(layer[i] == in[j]) {    // 找到layer[i]
                isLeft = true;    // layer[i]在左子树
                break;
            }
        }
        if(isLeft) layerLeft.push_back(layer[i]);    // 如果layer[i]在左子树，那么加入左子树层序
        else layerRight.push_back(layer[i]);    // 如果layer[i]在右子树，那么加入右子树层序
    }
    Node[root].lchild = create(layerLeft, inL, k - 1);    // 处理左子树
    Node[root].rchild = create(layerRight, k + 1, inR);    // 处理右子树
    return root;  //返回根结点地址
}
void preOrder(int root) {    // 先序
    if(root == -1) {
        return;
    }
    pre.push_back(Node[root].data);
    preOrder(Node[root].lchild);
    preOrder(Node[root].rchild);
}
void postOrder(int root) {    // 后序
    if(root == -1) {
        return;
    }
    postOrder(Node[root].lchild);
    postOrder(Node[root].rchild);
    post.push_back(Node[root].data);
}
int ans1 = 0;    // 从右往左：深度
void rightToLeftDFS(int root, int depth) {
    if(root == -1) {
        return;
    }
    if(depth > ans1) ans1 = depth;    // 更新ans1
    rightToLeftDFS(Node[root].lchild, depth + 1);    // 左孩子跟右孩子的深度都加1
    rightToLeftDFS(Node[root].rchild, depth + 1);
}
int ans2 = 0;    // 从右上往左下：往右的次数
void rightupToLeftdownDFS(int root, int right) {
    if(root == -1) {
        return;
    }
    if(right > ans2) ans2 = right;    // 更新ans2
    rightupToLeftdownDFS(Node[root].lchild, right);    // 往左时计数变量right不变
    rightupToLeftdownDFS(Node[root].rchild, right + 1);    // 往右时计数变量right加1
}
int minLeft = 0, maxRight = 0;    // 从上往下：最小负值，最大正值
void upToDownDFS(int root, int balance) {
    if(root == -1) {
        return;
    }
    if(balance > maxRight) maxRight = balance;    // 更新maxRight
    if(balance < minLeft) minLeft = balance;    // 更新minLeft
    upToDownDFS(Node[root].lchild, balance - 1);    // 往左时计数变量balance减1
    upToDownDFS(Node[root].rchild, balance + 1);    // 往右时计数变量balance加1
}
int main() {
    vector<int> layer;
    int n, temp;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &temp);
        layer.push_back(temp);    // 程序
    }
    for(int i = 0; i < n; i++) {
        scanf("%d", &in[i]);    // 中序
    }
    int root = create(layer, 0, n - 1);    //建树
    preOrder(root);    // 先序
    postOrder(root);    // 后序
    for(int i = 0; i < n; i++) {
        printf("%d", pre[i]);
        if(i < n - 1) printf(" ");
        else printf("\n");
    }
    for(int i = 0; i < n; i++) {
        printf("%d", post[i]);
        if(i < n - 1) printf(" ");
        else printf("\n");
    }
    rightToLeftDFS(root, 1);    // 从右往左，根结点深度为1
    rightupToLeftdownDFS(root, 1);    // 从右上往左下，根节点为第一个结点
    upToDownDFS(root, 0);    // 从上往下，根结点先不算在内
    printf("%d\n%d\n%d\n", ans1, ans2, maxRight - minLeft + 1);    // 三个解
    return 0;
}
