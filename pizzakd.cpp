#include<iostream>
using namespace std;

class pizza{
	int que[10];
	int r,f;
	public:
	pizza(){
		r=-1;
		f=-1;
		//for(int i=0;i<10;i++){
		//	que[i]=0;
		//
		
		
	}
	int isqfull();
	int isqempty();
	void enque(int);
	int deque();
	void pending();
};

int pizza::isqfull(){
	if((r+1)%10==f  || (f==0 && r==9)){
		return 1;
	}
	else{
		return 0;
	}
}


int pizza::isqempty(){
	if((f==-1) && (r==-1)){
		return 1;
	}
	else{
		return 0;
	}
}

void pizza::enque(int x){
	if(isqfull()){
		cout<<"\nAll orederd are placed .You will try next time!"<<endl;
	}
	else{
		if(f==-1  && r==-1){
			f=0;
			r=0;
			que[r]=x;
		}
		else{
			r=(r+1)%10;
			que[r]=x;
			cout<<"\nOrder placed succesfull!"<<endl;
		}
	}
}

int pizza::deque(){
	if(isqempty()){
		cout<<"\nAll order are process succesfully!"<<endl;
	}
	else{
		int h;
		f=(f+1)%10;
		h=que[f];
		cout<<"\nThis order "<<h<<" place succesfully!"<<endl;
	}
}

void pizza::pending(){
	if(!isqempty()){
		int g;
		g=f;
		while(g!=r){
			cout<<que[g]<<"-->";
			g=(g+1)%10;
		}
		cout<<que[g];
		
	}
	else{
		cout<<"\nThere are no pending orders."<<endl;
	}
}

int main(){
	pizza p1;
	int ch,n;
	char ans;
	cout<<"\n************  WELCOME TO PIZZA PARLOR  ************"<<endl;
	do{
	cout<<"\n1.place the order.\n2.process oreder.\n3.pending order.\n4.exit\nEnter your choice: ";
	cin>>ch;
	switch(ch){
		case 1:
			cout<<"\nEnter your id number: ";
			cin>>n;
			p1.enque(n);
			break;
		case 2:
			p1.deque();
			break;
		case 3:
			p1.pending();
			break;
		case 4:
			return 0;
			break;
		default:
			cout<<"\nWRONG CHOICE !"<<endl;
	}
	cout<<"\nDo you wnat to continue(y/n): ";
	
	cin>>ans;
	}while(ans=='y' || ans=='Y');
	return 0;
}
