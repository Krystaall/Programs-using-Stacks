#include<iostream>
#include<stack>
using namespace std;

bool isOperand(char c){
	if((c >='a' && c<='z')||(c >='A' && c<='Z')){
		return true;
	}
		else {
			return false;
		}

}

string postfixToInfix(string postfix){
	stack<string> s;      //here stack contains datatype string (unlike char in infix to postfix)
	for(int i=0; i<postfix.length(); i++){
		if(isOperand(postfix[i])){
			string op(1,postfix[i]);           //here 1 represent number of copies of postfix[i] u want in op string
			s.push(op);                         //also op line actually converts char postfix[i] into string datatype and store it in op
		}
		else{                  //if the symbol is not operand then it is ofc operator from input postfix string
			string op1= s.top();
			s.pop();
			string op2= s.top();
			s.pop();
			s.push("("+op2+postfix[i]+op1+")");
		}


	}
	return s.top();
}

int main(){
	string infix_exp, postfix_exp;
	cout<<"enter a postfix expression"<<endl;
	cin>>postfix_exp;
	stack<char> m ;
	cout<<"postfix expression:   "<<postfix_exp<<endl;
	infix_exp = postfixToInfix(postfix_exp);
	cout<<"infix expression:  "<<infix_exp<<endl;
	return 0;
}





