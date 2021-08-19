#include<iostream>
#include<stack>
#include<algorithm>           //included to reverse the given string
using namespace std;

bool isOperand(char c){
	if((c >='a' && c<='z')||(c >='A' && c<='Z')){
		return true;
	}
		else {
			return false;
		}

}

string prefixToInfix(string prefix){
	stack<string> s;
	string infix;
	for(int i=prefix.length()-1; i>=0;i--){        //in prefix we start ulta
		if(isOperand(prefix[i])){
			string op(1,prefix[i]);           //here 1 represent number of copies of postfix[i] u want in op string
			s.push(op);                         //also op line actually converts char postfix[i] into string datatype and store it in op
		}

	else{    //ofc now it is an operator
		string op1= s.top();
		s.pop();
		string op2= s.top();
		s.pop();
		s.push("("+op1+prefix[i]+op2+")");

	}
	}
	return s.top();
}

int main(){
	string infix_exp, prefix_exp;
	cout<<"enter a prefix expression"<<endl;
	cin>>prefix_exp;
	stack<char> s;
	cout<<"prefix expression:   "<<prefix_exp<<endl;
	infix_exp = prefixToInfix( prefix_exp);
	cout<<"infix expression:  "<<infix_exp<<endl;
	return 0;
}
