#include<iostream>
using namespace std;
class deq{
	public:
		int q[10];
		void ifr(int x);
		void ir(int x);
		void df();
		void dr();
		int r,f;
		void show();
		deq(){
		
		for(int i=0;i<10;i++){
			q[i]=0;
		}
		f=r=-1;
	}
		
		
			
		
};

void deq::ifr(int x){
	if(f==r+1){
		cout<<"Queue is full..."<<endl;
	}
	else if(f==-1){
		f=9;
		q[f]=x;
		
	}
	else{
		f--;
		q[f]=x;
		
	}
}

void deq::ir(int x){
	if(f==r+1){
		cout<<"Queue is full..."<<endl;
	}
	else if(r==-1){
		r=0;
		q[r]=x;
		
	}
	else{
			r++;
		q[r]=x;
	
	}
}

void deq::df(){
	if(f==-1 || f==10){
		cout<<"Queue is empty..."<<endl;
	}
	else{
		cout<<q[f]<<" is deleted..."<<endl;
		q[f]=0;
		f++;
	}
}

void deq::dr(){
	if(r==-1){
		cout<<"Queue is empty..."<<endl;
	}
	else{
		cout<<q[r]<<" is deleted..."<<endl;
		q[r]=0;
		r--;
	}
}

void deq::show(){
	cout<<endl;
	for(int i=0;i<10;i++){
		cout<<q[i]<<" ";
	}
	cout<<endl;
}

int main(){
	deq d;
	int ch,n;
	char ans;
	do{
		cout<<"\n1.Insert Front. \n2.insert Rear. \n3.Delete Front. \n4.Delete Rear. \n5.Show current status.";
        cout<<"Enter your choice : "<<endl;
        cin>>ch;
        switch(ch){
        	case 1:
        		cout<<"Enter element : "<<endl;
        		cin>>n;
        		d.ifr(n);
        		break;
        	case 2:
        		cout<<"Enter element : "<<endl;
        		cin>>n;
        		d.ir(n);
        		break;
        	case 3:
        		d.df();
        		break;
        	case 4:
        		d.dr();
        		break;
        	case 5:
        		d.show();
        		break;
        	default:
        		cout<<"Enter a valid choice..."<<endl;
		}
		cout<<"Do you want to chontine (y/n) ?" <<endl;
		cin>>ans;
}while(ans=='y' || ans =='Y');
	return 0;
}
