#include <bits/stdc++.h>
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

string intopost(string infix){
	stack<char> op;
	op.push('@');
	string postfix;
	
	for (int i = 0; i < infix.length(); i++){
		if(infix[i] >= '0' and  infix[i] <= '9'){
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
	return postfix;
}

bool isOperator(char x){
	if (x == '+' or x == '-' or x == '*' or x == '/' or x == '^'){
		return true;
	}
	return false;
}

int operasi(int y, int x, char z){
	if (z == '+'){
		return x + y;
	} else if (z == '-'){
		return x - y;
	} else if (z == '*'){
		return x * y;
	} else if (z == '.'){
		return x / y;
	} else if (z == '^'){
		return pow(x,y);
	} 
}

int post_evaluator(string postfix){
	stack<int> op;
	int tot = 0;
	for (int i = 0; i < postfix.length(); i++){
		if (isOperator(postfix[i])){
			if (op.size() != 1){
				//operand pertama
				int x = op.top();
				cout << x << '#';
				op.pop();
				//operang kedua
				int y = op.top();
				cout << y << endl;
				op.pop();
				tot = operasi(x, y, postfix[i]);
				cout << tot << "**\n";
				op.push(tot);
			} 
		} else {
			int z = int(postfix[i]);
			// ubah bilangan ASCII angka tersebut ke angka asli dengan dikurangi 48
			op.push(z-48);
		}
	}
	return tot;
}
int main (){
	string coba = "3+2*5";
	string hai = intopost(coba);
	cout << hai << endl;
	cout << post_evaluator(hai);
}
