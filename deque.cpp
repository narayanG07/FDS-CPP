#include<iostream>
using namespace std;

class deque{
	int que[10];
	int r,f,i;
	public:
	deque(){
		f=-1;
		r=-1;
		for(i=0;i<10;i++){
			que[i]=0;
		}
	}
	int isqempty();
	int isqfull();
	void insert_front(int);
	void insert_rear(int);
	int delete_front();
	int delete_rear();
	void show();
};

int deque::isqfull(){
	if((r+1)==f){
		return 1;
	}
	else{
		return 0;
	}
}

int deque::isqempty(){
	if(r==-1 && f==-1){
		return 1;
	}
	else{
		return 0;
	}
}

void deque::insert_front(int x){
	if(isqfull()){
		cout<<"\njob is full!";
	}
	else if(f==-1){
		f=9;
		que[f]=x;
	}
	else{
		f=f-1;
		que[f]=x;
	}
}

void deque::insert_rear(int y){
	if(isqfull()){
		cout<<"\nSorry,Queue is full";
	}
	else if(r==-1){
		r=0;
		que[r]=y;
	}
	else{
		r++;
		que[r]=y;
	}
}

int deque::delete_front(){
	if(isqempty()){
		cout<<"\nSorry que is already empty!";
	}
	else{
		int h;
		h=que[f];
		que[f]=0;
		f=f+1;
		cout<<"\njob "<<h<<" rwmoved!"<<endl;
	}
}

int deque::delete_rear(){
	if(isqempty()){
		cout<<"\nSorry Queue is empty!"<<endl;
	}
	else{
		int s;
		s=que[r];
		que[r]=0;
		r=r-1;
		cout<<"\njob "<<s<<" removed !"<<endl;
	}
}

void deque::show(){
	for(int i=0;i<10;i++){
		cout<<que[i]<<" | ";
	}
}
int main(){
	deque d1;
	int ch,k,m;
	char ans;
	cout<<"\n************* WELCOME ***********"<<endl;
	do{
	cout<<"\n1.Insert at front.\n2.Insert at rear.\n3.Delete at front.\n4.Delete at rear.\n5.show the status.\n6.Exit\nEnter your choice: ";
	cin>>ch;
	switch(ch){
		case 1:
			cout<<"\nEnter the element: ";
			cin>>k;
			d1.insert_front(k);
			break;
		case 2:
			cout<<"\nEnter the element: ";
			cin>>m;
			d1.insert_rear(m);
			break;
		case 3:
			d1.delete_front();
			break;
		case 4:
			d1.delete_rear();
			break;
		case 5:
			d1.show();
			break;
	    case 6:
	    	return 0;
	    	break;
	    default:
	    	cout<<"\nWRONG CHOICE!"<<endl;
	}
	cout<<"\nDo you want to continue(y/n): ";
	cin>>ans;
    }while(ans=='y' || ans=='Y');
	return 0;
}
