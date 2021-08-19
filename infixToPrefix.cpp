#include<iostream>
#include<stack>
#include<algorithm>           //included to reverse the given string
using namespace std;

bool isOperator(char c){
	if(c=='+' || c=='-'|| c=='*' || c=='/' || c=='^'){
		return true;}
		else {
			return false;
		}
}

int precedence(char c){

	if(c=='^')
		return 3;
	else if(c=='*' || c== '/')
		return 2;
	else if(c=='+' || c== '-')
		return 1;
	else
		return -1;
}

string infixToPrefix(stack<char> s, string infix){
	string prefix;
	reverse(infix.begin(), infix.end());    //here infix string is reversed.but brackets not reversed so we need to type code for it.
	for (int i=0; i<infix.length(); i++){
		if(infix[i]=='('){
			infix[i]=')';
		}
		else if(infix[i]==')'){
					infix[i]='(';
		}
	}

	for(int i=0; i<infix.length();i++){
		if((infix[i] >='a' && infix[i]<='z')||(infix[i] >='A' && infix[i]<='Z')){
					prefix+=infix[i];
				}
		else if(infix[i]=='('){
			s.push(infix[i]);
		}
		else if(infix[i]==')'){
			while((s.top()!='(')&& (!s.empty())){
				char temp=s.top();
				prefix+=temp;
				s.pop();
			}
			if(s.top()=='(')
			{
				s.pop();
			}

		}
		else if(isOperator(infix[i])){
			if(s.empty()){
				s.push(infix[i]);
			}
			else{
				if(precedence(infix[i])> precedence(s.top()))
			    {
					s.push(infix[i]);
				}
				else if((precedence(infix[i])==precedence(s.top()))&&(infix[i]=='^')){
					while((precedence(infix[i])==precedence(s.top())&&(infix[i]=='^'))){
					prefix+=s.top();
					s.pop();
					}
					s.push(infix[i]);
				}
				else if((precedence(infix[i])==precedence(s.top()))){
					s.push(infix[i]);
				}
				else{
					while((!s.empty())&& (precedence(infix[i])<precedence(s.top()))) {
						prefix+=s.top();
						s.pop();
					}
					s.push(infix[i]);
				}



			}

		}


	}
   while(!s.empty()){
	   prefix+=s.top();
	   s.pop();
   }
   //finally reverse the string and return it
   reverse(prefix.begin(), prefix.end());



	return prefix;
}

int main(){
	string infix_exp, prefix_exp;
	cout<<"enter a infix expression"<<endl;
	cin>>infix_exp;
	stack<char> s;
	cout<<"infix expression:   "<<infix_exp<<endl;
	prefix_exp = infixToPrefix(s, infix_exp);
	cout<<"prefix expression:  "<<prefix_exp<<endl;
	return 0;
}

