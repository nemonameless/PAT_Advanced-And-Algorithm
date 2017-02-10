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
bool isSame(int a[],int b[]){
	for(int i=0;i<n;i++){
		if(a[i]!=b[i])
			return false;
	}
	return true;
}
void show(int a[]){
	for(int i=0;i<n;i++){
		cout<<a[i];
		if(i<n-1)
			cout<<" ";
		else
			cout<<endl;
	}
}
bool insertSort(){
	bool flag=false;
	for(int i=1;i<n;i++){
		if(i!=1 && isSame(tmpOri,changed))
			flag=true;
		int tmp=origin[i],j=i;
		while(j>0 && tmpOri[j-1]>tmp){//////////////找插入位置
			tmpOri[j]=tmpOri[j-1];//////////////////////后移
			j--;
		}
		tmpOri[j]=tmp;   /////////////插入
		if(flag)
			return true;
	}
	return false;
}
void mergeSort(){
	bool flag=false;
	for(int step=2;step/2<=n;step*=2){       /////////归并
		if(step!=2 && isSame(tmpOri,changed))
			flag=true;
		for(int i=0;i<n;i+=step){			////////
			sort(tmpOri+i,tmpOri+min(i+step,n));
		}
		if(flag==true){
			show(tmpOri);
			return;
		}
	}
}
int main(){
	//freopen("G:\\PATdata\\A1089.txt","r",stdin);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>origin[i];
		tmpOri[i]=origin[i];
	}
	for(int i=0;i<n;i++){
		cin>>changed[i];
	}
	if(insertSort()){
		cout<<"Insertion Sort"<<endl;
		show(tmpOri);
	}else{
		cout<<"Merge Sort"<<endl;
		for(int i=0;i<n;i++)
			tmpOri[i]=origin[i];
		mergeSort();
	}
	return 0;
}