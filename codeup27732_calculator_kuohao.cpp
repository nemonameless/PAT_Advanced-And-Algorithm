//paste.ubuntu.com/15327777/
#include <iostream>
#include <cstdio>
#include <string>
#include <stack>
#include <queue>
#include <map>
using namespace std;
struct node {
    double num;     //操作数
    char op;        //操作符
    bool flag;      //true表示操作数，false表示操作符
};

string str;
stack<node> s;  //操作符栈
queue<node> q;  //后缀表达式序列
map<char,int> op;

void Change() {   //将中缀表达式转换为后缀表达式
    double num;
    node temp;
    for(int i = 0; i < str.length();) {
        if(str[i] >= '0' && str[i] <= '9') {    //如果是数字
            temp.flag = true;   //标记是数字数
            temp.num = str[i++] - '0';  //记录这个操作数的第一个数位
            while(i < str.length() && str[i] >= '0' && str[i] <= '9') {
                temp.num = temp.num * 10 + (str[i] - '0');  //更新这个操作数
                i++;
            }
            q.push(temp);   //将这个操作数压入后缀表达式的队列
        } else if(str[i] == '(') {    // 如果是左括号
            temp.op = str[i];
            s.push(temp);    // 直接入操作符栈
            i++;
        } else if(str[i] == ')') {    // 如果是右括号
            while(!s.empty() && s.top().op != '(') {    // 只要还没有到达左括号
                q.push(s.top());    // 将操作符栈顶不断弹出到后缀表达式的队列中
                s.pop();
            }
            s.pop();    // 弹出左括号，不入队
            i++;
        } else {    //如果是操作符
            temp.flag = false;  //标记是操作符
            //只要操作符栈的栈顶元素比该操作符优先级高
            //就把操作符栈栈顶元素弹出到后缀表达式的队列中
            while(!s.empty() && op[str[i]] <= op[s.top().op]) {
                q.push(s.top());
                s.pop();
            }
            temp.op = str[i];
            s.push(temp);//把该操作符压入操作符栈中
            i++;
        }
    }
    //如果操作符栈中还有操作符，就把它弹出到后缀表达式队列中
    while(!s.empty()) {
        q.push(s.top());
        s.pop();
    }
}
double Cal() {  //计算后缀表达式
    double temp1, temp2;
    node cur, temp;
    while(!q.empty()) {     //只要后缀表达式队列非空
        cur = q.front();    //cur记录队首元素
        q.pop();
        if(cur.flag == true) s.push(cur);   //如果是操作数，直接压入栈
        else {  //如果是操作符
            temp2 = s.top().num;    //弹出第二操作数
            s.pop();
            temp1 = s.top().num;    //弹出第一操作数
            s.pop();
            temp.flag = true;       //临时记录操作数
            if(cur.op == '+') temp.num = temp1 + temp2;         //加法
            else if(cur.op == '-') temp.num = temp1 - temp2;    //减法
            else if(cur.op == '*') temp.num = temp1 * temp2;    //乘法
            else temp.num = temp1 / temp2;  //除法
            s.push(temp);   //把该操作数压入栈
        }
    }
    return s.top().num;//栈顶元素就是后缀表达式的值
}

int main(){
	op['(']=op[')']=0;
	op['+']=op['-']=1;
	op['*']=op['/']=2;
	
	freopen("G:\\PATdata\\codeup27732.txt","r",stdin);

	while(getline(cin,str)){      //对于1918那题是while(getline(cin,str),str!='0')
		for(string::iterator it=str.end()-1;it!=str.begin();it--){
			if(*it==' ')
				str.erase(it);
		}
		while(!s.empty()){
			s.pop();
		}
		Change();
		printf("%.2f\n",Cal());
	}
	return 0;
}
