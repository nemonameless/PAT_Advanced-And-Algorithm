#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int n;
string deal(string s,int& e){
	int k=0;
	while(s.length()>0 && s[0]=='0'){
		s.erase(s.begin());
	}
	if(s[0]=='.'){	////////去掉前导零后是小数点，说明<1 
		s.erase(s.begin());
		while(s.length()>0 && s[0]=='0'){
			s.erase(s.begin());			//去掉小数点后的非零位前 所有0 
			e--;	/////////////////指数-- 
		}
	}else{
		while(k<s.length() && s[k]!='.'){/////////说明>1 
			k++;
			e++;			/////////没遇到小数点 指数就++ 
		}
		if(k<s.length()){	//////////遇到了小数点 
			s.erase(s.begin()+k);	///删除小数点 
		}
	}
	if(s.length()==0)/////////去掉前导零后s的长度变为0，说明这个数是0 
		e=0;
	int num=0;	//精度 
	k=0;
	string res;
	while(num<n){	///////精度还没到n 
		if(k<s.length())	///还有数字，就加到res末尾 
			res+=s[k++];
		else
			res+='0';
		num++;	
	}
	return res;
}


int main(){
	string s1,s2,s3,s4;
//	freopen("G:\\PATdata\\A1060.txt","r",stdin);
	cin >> n >> s1 >> s2;
	int e1=0,e2=0;
	s3=deal(s1,e1);
	s4=deal(s2,e2);
	if(s3==s4 && e1==e2)
		cout<<"YES 0."<<s3<<"*10^"<<e1<<endl;
	else
		cout<<"NO 0."<<s3<<"*10^"<<e1<<" 0."<<s4<<"*10^"<<e2<<endl;


	return 0;
}
