#include<cstdio>
#include<cstring>
#include<cctype>
#include<algorithm>
using namespace std;
int hass[100001]={},a[100001];
int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
		hass[a[i]]++;
	}
	int flag=0;
	for(int i=0;i<n;i++){//////////////i<n
		if(hass[a[i]]==1){
			printf("%d\n",a[i]);
			flag=1;
			break;
		}
	}
	//printf("\n");
	if(flag==0)
		printf("None\n");	
	return 0;
}


