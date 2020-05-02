#include <iostream>
#include <stack>
using namespace std;

int kasta(char x){
	if(x == '^'){
		return 3;
	}else if (x == '*' or x == '/'){
		return 2;
	}else if (x == '+' or x == '-'){
		return 1;
	} else {
		return -1;
	} 
}

void intopost(string infix){
	stack<char> op;
	op.push('@');
	string postfix;
	
	for (int i = 0; i < infix.length(); i++){
		if(infix[i] >= 'a' and  infix[i] <= 'z'){
			postfix += infix[i]; 
			
		} else if (infix[i] == '('){
			op.push('(');
		} else if (infix[i] == ')'){
			while(op.top() != '@' && op.top() != '('){
				char c = op.top();
				op.pop();
				postfix += c;
			}
			if (op.top() == '('){
				char c = op.top();
				op.pop();
			}
			
		} else{
			while(op.top() != '@' && kasta(infix[i]) <= kasta(op.top())){
				char c = op.top();
				op.pop();
				postfix += c;	
			}
			op.push(infix[i]);
		}
	}
	while(op.top() != '@') 
	{ 
		char c = op.top(); 
		op.pop(); 
		postfix += c; 
	} 
	cout << postfix;
}

int main (){
	string coba = "(a+b)^e-c*d";
	intopost(coba);
}
