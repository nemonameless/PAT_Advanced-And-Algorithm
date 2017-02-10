#include<cstdio>
#include<string>
#include<iostream>
#include<map>
#include<cctype>
using namespace std;
bool check(char c){
	if(isdigit(c) || isalpha(c))
		return true;
	return false;
}
int main(){
	string str;
	map<string,int> cnt;
	//freopen("G:\\PATdata\\A1071.txt","r",stdin);
	getline(cin,str);
	int i=0;
	while(i<str.length()){
		string word;
		while(i<str.length() && check(str[i])){
			if(isupper(str[i]))
				str[i]=tolower(str[i]);
			word+=str[i];
			i++;
		}
		if(word!=""){
			if(cnt.find(word)==cnt.end())
				cnt[word]=1;
			else
				cnt[word]++;
		}
		while(i<str.length() && check(str[i])==false){
			i++;
		}
	}
	string ans;
	int max=0;
	for(map<string,int>::iterator it=cnt.begin();it!=cnt.end();it++){
		if(it->second>max){
			max=it->second;
			ans=it->first;
		}
	}
	cout<<ans<<" "<<max<<endl;
	return 0;
}