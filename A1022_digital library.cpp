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
map<string,set<int> > mptitle,mpauthor,mpkey,mppub,mpyear;
void query(map<string,set<int> >& mp,string& str){///////////////////&
	if(mp.find(str)==mp.end())
		printf("Not Found\n");
	else{
		for(set<int>::iterator it=mp[str].begin();it!=mp[str].end();it++){
			printf("%07d\n",*it);
		}
	}
}
int main(){
	int n,m,id,type;
	//	freopen("G:\\PATdata\\A1022.txt","r",stdin);
	scanf("%d",&n);
	string title,author,key,pub,year;
	for(int i=0;i<n;i++){
		scanf("%d",&id);
		char c=getchar();
		getline(cin,title);
		mptitle[title].insert(id);
		getline(cin,author);
		mpauthor[author].insert(id);
		while(cin>>key){
			mpkey[key].insert(id);
			c=getchar();
			if(c=='\n')
				break;
		}
		getline(cin,pub);
		mppub[pub].insert(id);
		getline(cin,year);
		mpyear[year].insert(id);
	}
	string tmp;
	scanf("%d",&m);
	for(int i=0;i<m;i++){
		scanf("%d: ",&type);//////////////////读入格式要对好
		getline(cin,tmp);
		cout<<type<<": "<<tmp<<endl;
		switch(type){
			case 1:query(mptitle,tmp);break;
			case 2:query(mpauthor,tmp);break;
			case 3:query(mpkey,tmp);break;
			case 4:query(mppub,tmp);break;
			default:query(mpyear,tmp);break;
		}
	}

	return 0;
}