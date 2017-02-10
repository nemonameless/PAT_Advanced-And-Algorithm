#include<cstdio>
#include<string>
#include<map>
#include<iostream>
#include<cctype>
using namespace std;
string unitnum[13]={"tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};
string tennum[13]={"tret", "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};
string num2str[170];
map<string,int> str2num;
void init(){
	for(int i=0;i<13;i++){
		num2str[i]=unitnum[i];
		str2num[unitnum[i]]=i;
		num2str[i*13]=tennum[i];
		str2num[tennum[i]]=i*13;
	}
	for(int i=1;i<13;i++){
		for(int j=1;j<13;j++){
			string str=tennum[i]+" "+unitnum[j];
			num2str[13*i+j]=str;
			str2num[str]=i*13+j;
		}
	}
}
int main(){
	init();
	int t;
	freopen("G:\\PATdata\\A1100.txt","r",stdin);
	scanf("%d%*c",&t);/////////////////////
	while(t--){
		string str;
		getline(cin,str);//////////////
		if(isdigit(str[0])){
			int num=0;
			for(int i=0;i<str.length();i++){
				num = num*10+(str[i]-'0');
			}
			cout<< num2str[num]<<endl;
		}else
			cout<< str2num[str]<<endl;
	}
	return 0;
}