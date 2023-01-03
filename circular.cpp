#include<iostream>
using namespace std;

class circular{
	int que[7];
	int r,f;
	public:
		circular(){
			r=-1;
			f=-1;
		}
		int isqfull();
		int isqempty();
		void enque(int);
		void display();
		void deque();
};


int circular::isqfull(){
	if((r+1)%7==f || (f==0 && r==6)){
		return 1;
	}
	else{
		return 0;
	}
}

int circular::isqempty()
{
	if(f==-1 && r==-1){
		return 1;
	}
	else{
		return 0;
	}
	
}

void circular::enque(int m){
	if(isqfull()){
		cout<<"\nSorry! You can't add another element"<<endl;
	}
	else{
		if(f==-1 && r==-1){
			f=0;
			r=0;
			
		}
		else{
			r=(r+1)%7;
			que[r]=m;
			//cout<<"\nthis is added "<<que[r]<<" succesfully"<<endl;
		}
	}
}



/*
void circular::enque(int x){
	if(r==f==-1){
		r=0;
		f=0;
	}
	else if((r+1)%7==f){
		cout<<"\nQueue is full"<<endl;
	}
	else{
		r=(r+1)%7;
		que[r]=x;
		
	}
}

void circular::deque(){
	if(r==-1 && f==-1){
		cout<<"\nQueue is empty"<<endl;
	}
	else if(f==r){
		//cout<<"\n"<<que[f]<<" removed succesfully!"<<endl;
		f=-1;
		r=-1;
	}
	else{
		//cout<<"\nJob "<<que[f]<<" removed succesfully!"<<endl;
		f=(f+1)%7;
		cout<<"\nJob "<<que[f]<<" removed succesfully!"<<endl;
	}
}
*/

void circular::deque(){
	if(isqempty()){
		cout<<"\nSorry you cant delete "<<endl;
	}
	else{
		if(f==r){
			f=-1;
			r=-1;
		}
		cout<<"\nJob "<<que[f]<<" removed succesfully!"<<endl;
		f=(f+1)%7;
		
	}
}

void circular::display(){
	int i=f;
	if((f==-1) &&(r==-1)){
		cout<<"\nQueue is empty"<<endl;
	}
	else{
		while(i!=r){
			cout<<"\t"<<que[i];
			i=(i+1)%7;
		}
		cout<<"\t"<<que[i];
	}
	
}



int main(){
	circular c1;
	int ch,k,l;
	char ans;
	cout<<"\n**************Welcone to circular que*****************"<<endl;
	do{
	
	cout<<"\n1.Insert the element.\n2.delete the element.\n3.Show thw status.\n4.Exit.\nEnter the choice: ";
	cin>>ch;
	/*cout<<"\nHow many elements you have to add : ";
	cin>>l;
	while(l>0){
		cout<<"\nEnter the element you want to insert: ";
	    cin>>k;
	    c1.enque(k);
	    l--;
	}
	c1.display();
	c1.deque();
	c1.deque();
	c1.deque();
	c1.display();
	
	*/
	switch(ch){
		case 1:
			cout<<"Enter the element you want to insert: ";
			cin>>k;
			c1.enque(k);
			break;
	    case 2:
	    	c1.deque();
	    	break;
	    case 3:
	    	c1.display();
	    	break;
	    case 4:
	    	return 0;
	    	break;
	    default:
	    	cout<<"\Enter the valid choice !!"<<endl;
	}
	cout<<"\nDo you want to continue(y/n): ";
	cin>>ans;
    }while(ans=='y'||ans=='Y');
	return 0;
}
