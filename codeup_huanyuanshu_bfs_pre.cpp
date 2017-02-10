//paste.ubuntu.com/10616131/
//
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
const int maxn = 50;
struct node {
    int data;
    node* lchild;
    node* rchild;
};
int in[maxn];    //中序

//当前二叉树的层序序列为layer，中序序列区间为[inL, inR]
//create函数返回构建出的二叉树的根结点地址
node* create(vector<int> layer, int inL, int inR) {
    if(layer.size() == 0) {
        return NULL;
    }
    node* root = new node;  //新建一个新的结点，用来存放当前二叉树的根结点
    root->data = layer[0];  //新结点的数据域为根结点的值
    int k;
    for(k = inL; k <= inR; k++) {
        if(in[k] == layer[0]) {
            break;
        }
    }
    vector<int> layerLeft;
    vector<int> layerRight;
    for(int i = 1; i < layer.size(); i++) {
        bool isLeft = false;
        for(int j = inL; j < k; j++) {
            if(layer[i] == in[j]) {
                isLeft = true;
                break;
            }
        }
        if(isLeft) {
            layerLeft.push_back(layer[i]);
        } else {
            layerRight.push_back(layer[i]);
        }
    }
    root->lchild = create(layerLeft, inL, k - 1);
    root->rchild = create(layerRight, k + 1, inR);
    return root;  //返回根结点地址
}

int num;
void preOrder(node* root,int n) {
    if(root == NULL) {
        return;
    }
    printf("%d", root->data);
    num++;
    if(num < n) printf(" ");
    else printf("\n");
    preOrder(root->lchild, n);
    preOrder(root->rchild, n);
}

void postOrder(node* root,int n) {
    if(root == NULL) {
        return;
    }
    postOrder(root->lchild, n);
    postOrder(root->rchild, n);
    printf("%d", root->data);
    num++;
    if(num < n) printf(" ");
    else printf("\n");
}

int main() {
        vector<int> layer;
        int n, temp;
        scanf("%d", &n);
        for(int i = 0; i < n; i++) {
            scanf("%d", &temp);
            layer.push_back(temp);
        }
        for(int i = 0; i < n; i++) {
            scanf("%d", &in[i]);
        }
        node* root = create(layer, 0, n - 1);    //建树
        num = 0;
        preOrder(root, n);
        num = 0;
        postOrder(root, n);
    return 0;
}
