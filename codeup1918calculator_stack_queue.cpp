#include<iostream>
#include<cstdio>
#include<string>
#include<map>
#include<queue>
#include<stack>
#include<cctype>
using namespace std;
string str;
struct node{
	double num;
	char sig_op;
	bool flag;
};
queue<node> q;
stack<node> s;
map<char,int> op;///////////
void change(){
	double num;
	node tmp;
	for(int i=0;i<str.length();){
		if(isdigit(str[i])){
			tmp.flag=true;
			tmp.num=str[i++]-'0';
			while(i<str.length() && isdigit(str[i])){
				tmp.num=tmp.num*10+str[i]-'0';
				i++;
			}
			q.push(tmp);
		}else{
			tmp.flag=false;

			while(!s.empty() && op[str[i]]<= op[s.top().sig_op]){
				q.push(s.top());
				s.pop();
			}
			tmp.sig_op=str[i];
			s.push(tmp);
			i++;
		}
	}
	while(!s.empty()){
		q.push(s.top());
		s.pop();
	}
	
}

double cal(){
	double tmp1,tmp2;
	node tmp,now;
	while(!q.empty()){
		now=q.front();
		q.pop();
		if(now.flag==true)
			s.push(now);
		else{
			tmp2=s.top().num;
			s.pop();
			tmp1=s.top().num;
			s.pop();
			tmp.flag=true;
			if(now.sig_op=='+')
				tmp.num=tmp1+tmp2;
			else if(now.sig_op=='-')
				tmp.num=tmp1-tmp2;
			else if(now.sig_op=='*')
				tmp.num=tmp1*tmp2;
			else 
				tmp.num=tmp1/tmp2;

			
			s.push(tmp);
		}
	}
	return s.top().num;
}

int main(){
	op['+']=op['-']=1;
	op['*']=op['/']=2;
	freopen("G:\\PATdata\\codeup1918.txt","r",stdin);
	while(getline(cin,str),str!="0"){
		for(string::iterator it=str.end()-1;it!=str.begin();it--){
			if(*it==' ')
				str.erase(it);
		}
		while(!s.empty()){
			s.pop();
		}
		change();
		printf("%.2f\n",cal());
	}
	return 0;
}

