#include<iostream>
using namespace std;

class jobque{
	int que[20];
	int r,f;
	public:
		jobque(){
			r=-1;
			f=-1;
		}
		int isqfull();
		int isqempty();
		void enque(int);
		int deque();
		void display();
};

int jobque::isqfull(){
	if(r==19){
		return 1;
	}
	else{
		return 0;
	}
}

int jobque::isqempty(){
	if(f>r || r==f==-1){
		return 1;
	}
	else{
		return 0;
	}
}

void jobque::enque(int x){
	if(isqfull()){
		cout<<"\n Queue is full"<<endl;
	}
	else{
		if(f==r==-1){
			f=0;
			r=0;
		}
		que[r]=x;
		r++;
		//r=r+1;
		//que[r]=x;
	}
}


int jobque::deque(){
	if(isqempty()){
		cout<<"\n Queue is already empty "<<endl;
	}
	else{
		int h;
		h=que[f];
		f=f+1;
		cout<<"\nJob "<<h<<" processed succesfully"<<endl;
		
	}
}

void jobque::display(){
	int i;
	for(i=f;i<r;i++){
		cout<<"\n"<<que[i];
	}
}

int main(){
	jobque j1;
	int ch,t;
	char ans;
	cout<<"\n********************welcome to jobque**************************"<<endl;
	do{
	
	cout<<"\n1.insert the element. \n2.delete the element. \n3.show the status. \n4.exit"<<endl;
	cout<<"Enter the choice: ";
	cin>>ch;
	switch(ch){
		case 1:
			cout<<"Enter the element :";
			cin>>t;
			j1.enque(t);
			break;
		case 2:
			j1.deque();
			break;
		case 3:
			j1.display();
			break;
		case 4:
			return 0;
			break;
	}cout<<"\nDo you want to continue(y/n):"<<endl;
	cin>>ans;
	}while(ans=='y' || ans=='Y');
	return 0;
}
