#include<iostream>
using namespace std;

class pallin{
	char s1[20];
	char s2[20];
	char rev[20];
	int top;
	public:
	//char rev[20];
	pallin(){
		top=-1;
	}
	int isstackfull();
	int isstackempty();
	void push(char);
	char pop();
	void checkpallin();
};

int pallin::isstackfull(){
	if(top==19){
		
		return 1;
	}
	else{
		return 0;
	}
}

int pallin::isstackempty(){
	if(top==-1){
		return 1;
	}
	else{
		return 0;
	}
}

void pallin::push(char x){
	top=top+1;
	s2[top]=x;
}

char pallin::pop(){
	char x2;
	
	x2=s2[top];
	top--;

	return x2;
}

void pallin::checkpallin(){
	int i=0;
	int flag=0;
	char p,k;
	//cout<<"\n##############   WELCOME    ###########"<<endl;
	cout<<"\nEnter the string "<<endl;
	cin>>s1;
	
	while(s1[i]!='\0'){
		p=s1[i];
		
		
		push(p);
		i++;
	}
	
    i=0;
	while(!isstackempty()){
		rev[i]=pop();
		i++;
	}
	
	//cout<<"\nReverse string "<<rev;
	i=0;
	while(s1[i]!='\0'){
		if(rev[i]==s1[i]){
			i++;
		}
		else{
			flag=1;
			break;
		}
	}
	
	if(flag==1){
		cout<<"\nGiven string is  not pallindrome"<<endl;
	}
	else{
		cout<<"\nGiven string is pallindrome"<<endl;
	}
		
}

int main(){
	pallin p1;
	char ans;
	cout<<"\n###############   WELCOME    ###############"<<endl;
	do{
		p1.checkpallin();
		cout<<"\n*************do you want to continue(y/n)*************"<<endl;
		cin>>ans;
	}while(ans=='y' || ans=='Y');
	return 0;
}
	

