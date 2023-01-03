#include<iostream>
using namespace std;
class palin{
	public:
		char original[20];
		char stack[20];
		char rev[20];
		int top;
		palin(){
			top=-1;
		}
		int full();
		int empty();
		void push(char x);
		char pop();
		void fun();
};

int palin::full(){
	if(top==19){
		return 1;
	}
	else{
		return 0;
	}
}

int palin::empty(){
	if(top==-1){
		return 1;
	}
	else{
		return 0;
	}
}

void palin::push(char x){
		top=top+1;
		stack[top]=x;
	
}

char palin::pop(){
	char x;
	x=stack[top];
	top--;
	return x;
}

void palin::fun(){
	cout<<"Enter : "<<endl;
	cin>>original;
	char y;
	int i=0;
	while(original[i]!='\0'){
		if(original[0]==')' || original[0]==']' || original[0]=='}'){
			cout<<"Not parenthesized !!!"<<endl;
			break;
		}
		else{
			y=original[i];
			switch(y){
				case '(':
					push(y);
					i++;
					break;
				case '{':
					push(y);
					i++;
					break;
				case '[':
					push(y);
					i++;
					break;
				case ']':
					pop();
					i++;
					break;
				case '}':
					pop();
					i++;
					break;
				case ')':
					pop();
					i++;
					break;
			}
		}
	}
	if(empty()){
		cout<<"Given string is parenthesized "<<endl;
		
	}
	else{
		cout<<"Given string Not parenthesized ! "<<endl;
	}
}



int main(){
	palin j;
	j.fun();
	
	return 0;
}
