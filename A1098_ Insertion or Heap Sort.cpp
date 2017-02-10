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
const int maxn=110;
int origin[maxn],tmpOri[maxn],changed[maxn];
int n;
void show(int a[]){
	for(int i=1;i<=n;i++){
		cout<<a[i];
		if(i<n)
			cout<<" ";
		else
			cout<<endl;
	}
}
bool issame(int a[],int b[]){
	for(int i=1;i<=n;i++){
		if(a[i]!=b[i])
			return false;
	}
	return true;
}
bool insertSort() {
    bool flag = false;
    for(int i = 2; i <= n; i++) {
        if(i > 2 && issame(tmpOri, changed)) {
            flag = true;
        }
		sort(tmpOri,tmpOri+1+i);
        if(flag == true) {
            return true;
        }
    }
    return false;
}
void downAdjust(int low,int high){
	int i=low,j=i*2;
	while(j<=high){      //////////////////存在孩子<=
		if(j+1<=high && tmpOri[j+1]>tmpOri[j]){/////////存在右孩子，且右孩子比左孩子大,<=,>
			j=j+1;       /////让j存储右孩子下标
		}
		if(tmpOri[j]>tmpOri[i]){
			swap(tmpOri[j],tmpOri[i]);   ////////最大孩子 与 父亲交换
			i=j;     
			j=2*i;/////进入下一层
		}else{
			break;
		}
	}
}
void heapSort(){
	bool flag=false;
	for(int i=n/2;i>=1;i--){ ////////////从 n/2往前
		downAdjust(i,n);///////////建堆
	}
	for(int i=n;i>1;i--){
		if(i!=n && issame(tmpOri,changed))////////////////////是和changed对比，不是origin
			flag=true;
		swap(tmpOri[i],tmpOri[1]);/////////////交换堆顶
		downAdjust(1,i-1);//////调整堆顶
		if(flag == true){
			show(tmpOri);
			return;
		}
	}
}
int main(){
//	freopen("G:\\PATdata\\A1098.txt","r",stdin);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>origin[i];
		tmpOri[i]=origin[i];
	}
	for(int i=1;i<=n;i++){
		cin>>changed[i];
	}
	if(insertSort()){////////////insertSort不能少括号，否则始终输出Insertion Sort
		cout<<"Insertion Sort"<<endl;
		show(tmpOri);
	}else{
		cout<<"Heap Sort"<<endl;
		for(int i=1;i<=n;i++){
			tmpOri[i]=origin[i];
		}
		heapSort();
	}
	return 0;
}