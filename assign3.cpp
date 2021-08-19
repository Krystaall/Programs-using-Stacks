/*
 * Roll no.- 2459
 * Name- Sharvari Sonkusare
 * CNumber- C22019221458
 * Assignment number- 3
 *
 * Problem statement -
 * Implement Stack as ADT using linked list or array. Use the same ADT to evaluate a given
postfix expression.
 * */

//STACK USING LINKED LIST
#include<iostream>
#include<stack>
#include<math.h>
using namespace std;

class Node{
public:
	int val;
	Node* next;

	Node(){
		val=0;
		next= NULL;
	}
	Node(int v){
		val=v;
	}
};
class stack_ll{
public:
	Node* top;
	int c=0;
	stack_ll(){
		top= NULL;
	}


bool isEmpty(){
	if(top==NULL){
		return true;
	}
	else{
		return false;
	}
}


void push(int v, int n){
	if(c==n){
		cout<<"STACK OVERFLOW (cannot insert the value)"<<endl;
	}
	else{
	Node* temp= new Node();
	temp->val= v;
	temp->next= top;
	top=temp;
	c+=1;
	cout<<"value pushed"<<endl;
	}
}

void pop(){
	if(top==NULL){
		cout<<"stack underflow"<<endl;
	}
	else{
		cout<<"the popped element is "<<top->val<<endl;
		top=top->next;
		c=c-1;
	}
}
void display(){
	Node* ptr;
	if(top==NULL){
		cout<<"stack is empty"<<endl;;
	}
	else{
	ptr=top;
	cout<<"the stack elements are: "<<endl;
	while(ptr!= NULL){
		cout<<ptr->val<<" "<<endl;
		ptr=ptr->next;
	}
	}
}
int count(){
	return c;
}

bool isOperand(char c){
	if((c >='a' && c<='z')||(c >='A' && c<='Z')){
		return true;
	}
		else {
			return false;
		}

}



string postfixToInfix(string postfix){
	stack<string> s;          //here stack contains data type string (unlike char in infix to postfix)
	stack<int> m;
	int c;

	for(int i=0; i<postfix.length(); i++){

		 if(isOperand(postfix[i])){
			string op(1,postfix[i]);    //here 1 represent number of copies of postfix[i] u want in op string
			s.push(op);    //also op line actually converts char postfix[i] into string datatype and store it in op

		 }
		 else{       //if the symbol is not operand then it is ofc operator from input postfix string
			string op1= s.top();
			s.pop();
			string op2= s.top();
			s.pop();
			s.push("("+op2+postfix[i]+op1+")");

		 }
		cout<<c;
	}

	return s.top();
}

bool isNum(char c){
	if(c >='0' && c<='9'){
		return true;
	}
		else {
			return false;
		}

}

float scanNum(char m){
	int value;
	value=m;
	return float(value-'0');
}


bool isOperator(char m){
	if(m=='+' || m=='-' || m=='*' || m=='/' || m=='^'){
		return true;
	}
	else
		return false;

}

float operation(int a, int b, char op){
	if(op=='+'){
		return b+a;
	}
	else if(op=='-'){
		return b-a;
	}
	else if(op=='*'){
			return b*a;
		}
	else if(op=='/'){
			return b/a;
		}
	else if(op=='^'){
			return pow(b,a);
		}

}

float evaluate(string postfix){
	stack<float> s;
	int a,b;
	for(int i=0; i<postfix.length(); i++){
		if(isOperator(postfix[i])){
			a= s.top();
			s.pop();
			b= s.top();
			s.pop();
			s.push(operation(a,b,postfix[i]));
		}
		else if(isNum(postfix[i])){
			s.push(scanNum(postfix[i]));

		}
	}

return s.top();
}







void isFull(int n){
	if(c==n){
		cout<<"The stack is full. Further insertion can cause Stack overflow"<<endl;
	}
}


};

int main(){
	stack_ll s;
	stack<char> m;
	int d, ch,n;
	cout<<"Enter the max size of the stack"<<endl;
	cin>>n;
	do{
		cout<<"\nEnter a choice. Enter 0 if u want to exit"<<endl;
		cout<<"1.isEmpty"<<endl;
		cout<<"2.push"<<endl;
		cout<<"3.pop"<<endl;
		cout<<"4.display"<<endl;
		cout<<"5.count"<<endl;
		cout<<"6.isFull"<<endl;
		cout<<"7.postfix expression to infix expression"<<endl;
		cout<<"8. Evaluate postfix expression"<<endl;

		cin>>ch;
		switch(ch){
		case 0:
			cout<<"EXIT"<<endl;
		break;
		case 1: if(s.isEmpty()){
			cout<<"the stack is empty"<<endl;
		}
		else{
			cout<<"stack is not empty"<<endl;
		}
		break;
		case 2: cout<<"enter the value u want to push"<<endl;
		cin>>d;
		s.push(d,n);
		break;
		case 3:
			s.pop();
			break;
		case 4:
			s.display();
			break;
		case 5:
			cout<<"the count is "<< s.count()<<endl;;
			break;
		case 6:
			s.isFull(n);
			break;
		case 7:{
			string infix_exp, postfix_exp;
			cout<<"enter a postfix expression"<<endl;
			cin>>postfix_exp;
			cout<<"postfix expression:   "<<postfix_exp<<endl;
			infix_exp = s.postfixToInfix(postfix_exp);
			cout<<"infix expression:  "<<infix_exp<<endl;
			break;
		}
		case 8:{
			string  p_exp;
			int x;
			cout<<"enter a postfix expression for evaluation(use digits)"<<endl;
			cin>>p_exp;
			cout<<"The value of expression is: ";
			x= s.evaluate(p_exp);
			cout<<x;
			break;
		}

		default:
			cout<<"enter a valid choice"<<endl;
		}

	}while(ch!=0);
return 0;
}

/*
 OUTPUT:
 Enter the max size of the stack
5

Enter a choice. Enter 0 if u want to exit
1.isEmpty
2.push
3.pop
4.display
5.count
6.isFull
7.Evaluate postfix expression
8. Evaluate postfix expression
1
the stack is empty

Enter a choice. Enter 0 if u want to exit
1.isEmpty
2.push
3.pop
4.display
5.count
6.isFull
7.Evaluate postfix expression
8. Evaluate postfix expression
2
enter the value u want to push
1
value pushed

Enter a choice. Enter 0 if u want to exit
1.isEmpty
2.push
3.pop
4.display
5.count
6.isFull
7.Evaluate postfix expression
8. Evaluate postfix expression
2
enter the value u want to push
2
value pushed

Enter a choice. Enter 0 if u want to exit
1.isEmpty
2.push
3.pop
4.display
5.count
6.isFull
7.Evaluate postfix expression
8. Evaluate postfix expression
2
enter the value u want to push
3
value pushed

Enter a choice. Enter 0 if u want to exit
1.isEmpty
2.push
3.pop
4.display
5.count
6.isFull
7.Evaluate postfix expression
8. Evaluate postfix expression
3
the popped element is 3

Enter a choice. Enter 0 if u want to exit
1.isEmpty
2.push
3.pop
4.display
5.count
6.isFull
7.Evaluate postfix expression
8. Evaluate postfix expression
2
enter the value u want to push
4
value pushed

Enter a choice. Enter 0 if u want to exit
1.isEmpty
2.push
3.pop
4.display
5.count
6.isFull
7.Evaluate postfix expression
8. Evaluate postfix expression
2
enter the value u want to push
5
value pushed

Enter a choice. Enter 0 if u want to exit
1.isEmpty
2.push
3.pop
4.display
5.count
6.isFull
7.Evaluate postfix expression
8. Evaluate postfix expression
2
enter the value u want to push
6
value pushed

Enter a choice. Enter 0 if u want to exit
1.isEmpty
2.push
3.pop
4.display
5.count
6.isFull
7.Evaluate postfix expression
8. Evaluate postfix expression
2
enter the value u want to push
7
STACK OVERFLOW

Enter a choice. Enter 0 if u want to exit
1.isEmpty
2.push
3.pop
4.display
5.count
6.isFull
7.Evaluate postfix expression
8. Evaluate postfix expression
4
the stack elements are:
6
5
4
2
1

Enter a choice. Enter 0 if u want to exit
1.isEmpty
2.push
3.pop
4.display
5.count
6.isFull
7.Evaluate postfix expression
8. Evaluate postfix expression
5
the count is 5

Enter a choice. Enter 0 if u want to exit
1.isEmpty
2.push
3.pop
4.display
5.count
6.isFull
7.Evaluate postfix expression
8. Evaluate postfix expression
3
the popped element is 6

Enter a choice. Enter 0 if u want to exit
1.isEmpty
2.push
3.pop
4.display
5.count
6.isFull
7.Evaluate postfix expression
8. Evaluate postfix expression
5
the count is 4

Enter a choice. Enter 0 if u want to exit
1.isEmpty
2.push
3.pop
4.display
5.count
6.isFull
7.Evaluate postfix expression
8. Evaluate postfix expression
4
the stack elements are:
5
4
2
1

Enter a choice. Enter 0 if u want to exit
1.isEmpty
2.push
3.pop
4.display
5.count
6.isFull
7.Evaluate postfix expression
8. Evaluate postfix expression
7
enter a postfix expression
ab+c*
postfix expression:   ab+c*
infix expression:  ((a+b)*c)

Enter a choice. Enter 0 if u want to exit
1.isEmpty
2.push
3.pop
4.display
5.count
6.isFull
7.postfix expression to infix expression
8. Evaluate postfix expression
8
enter a postfix expression for evaluation(use digits)
21+3*
The value of expression is: 9

Enter a choice. Enter 0 if u want to exit
1.isEmpty
2.push
3.pop
4.display
5.count
6.isFull
7.Evaluate postfix expression
8. Evaluate postfix expression
0
EXIT


TIME COMPLEXITIES:

1. isEmpty=O(1)
2. push= O(1)
3. pop= O(1)
4. display=O(n)
5. count=O(1)
6. isOperand=O(1)
7. isNum=O(1)
8. postfixToInfix=O(n)
9. scanNum=O(1)
10. evaluate =O(n)
11. isOperator=O(1)
12. operation=O(1)
13. isFull= O(1)

*/






