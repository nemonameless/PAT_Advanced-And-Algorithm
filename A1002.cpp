#include<cstdio>
using namespace std;
const int max=1001;
int main(){
	int k,n,cnt=0;
	double a,p[max]={0};
	freopen("G:\\PATdata\\A1002.txt","r",stdin);
	scanf("%d",&k);
	for(int i=0;i<k;i++){
		scanf("%d %lf",&n,&a);
		p[n]+=a;
	}
	scanf("%d",&k);
	for(int i=0;i<k;i++){
		scanf("%d %lf",&n,&a);
		p[n]+=a;
	}
	for(int i=0;i<max;i++){
		if(p[i]!=0)
			cnt++;
	}
	/*printf("%d ",cnt);
	for(int i=max-1;i>=0;i--){
		
		if(p[i]!=0){
			cnt--;
			if(cnt>0)
				printf("%d %.1f ",i,p[i]);
			else
				printf("%d %.1f\n",i,p[i]);
			
		}
	}
	*/
	 printf("%d",cnt);
  for(int i=max-1;i>=0;i--){
    
    if(p[i]!=0){
      printf(" %d %.1f",i,p[i]);
      
    }
  }

	return 0;
}