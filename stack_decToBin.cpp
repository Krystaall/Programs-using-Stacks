#include<iostream>
using namespace std;           //stack using array
class Stack{
private:

	int top;
	int arr[100];
public:
	Stack(){
		top=-1;
		for(int i=0;i<99;i++){
			arr[i]=0;
		}
	}
	bool isEmpty(){
		if(top==-1){
				return true;
			}
			else{
				return false;
			}
	}
	bool isFull(){
		if(top==99){
			return true;
			}
			else{
				return false;
			}

	}
	void push(int val){
		if(isFull()){
			cout<<"stack overflow"<<endl;
		}
		else{
			top++;
			arr[top]=val;
		}
	}
	int pop(){
	if(isEmpty()){
		cout<<"the stack is empty"<<endl;

	}
	else{
		int popvalue= arr[top];
		arr[top]=0;
		top--;
		return popvalue;
	}

	}

};
 int main(){
	Stack s;
	int n;
	cout<<"Enter a number"<<endl;
	cin>>n;
	while(n>0){
		int rem=n%2;
		n=n/2;
		s.push(rem);
		}
	cout<<"the binary form is: "<<endl;
	while(!s.isEmpty()){
		int item;
		item=s.pop();
		cout<<item;
	}
}




