#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
const int maxn=10001;
int matix[maxn][maxn],a[maxn];
bool cmp(int a,int b){

	return a>b;
}
int main(){
	int N;
	freopen("G:\\PATdata\\A1105.txt","r",stdin);
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		scanf("%d",&a[i]);
	}
	if(N==1){
		printf("%d\n",a[0]);
		return 0;
	}

	sort(a,a+N,cmp);
	int m=(int)ceil(sqrt(1.0*N));////////////////////// 
	while(N%m!=0)
		m++;
	int n=N/m,i=1,j=1,now=0;
	int left=1,up=1,right=n,down=m;

	while(now<N){
		while(now<N && j<right){
			matix[i][j++]=a[now++];	
		}
		while(now<N && i<down){
			matix[i++][j]=a[now++];	
		}
		while(now<N && j>left){
			matix[i][j--]=a[now++];	
		}
		while(now<N && i>up){
			matix[i--][j]=a[now++];	
		}
		
		i++;j++;
		up++,left++;right--,down--;
			if(now==N-1)
						matix[i][j]=a[now++];
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			printf("%d",matix[i][j]);
			if(j<n)
				printf(" ");
			else
				printf("\n");
		}
	}


	return 0;
}
