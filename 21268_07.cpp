#include <iostream>
using namespace std;

class Node{
	public:
	Node* next;
	Node* prev;
	int seat_num;
	int booking_status;
};

class Cinemax{
public:
	Node* head, * tail, * temp;
	Cinemax(){
		head = NULL;
	}
	void Create();
	void Display();
	void Book();
	void Cancel();

};

void Cinemax::Create(){
	int i = 1;
	temp = new Node;
	temp->seat_num = 1;
	temp->booking_status = 0;
	tail = head = temp;

	for(int i=2; i<=70; i++){
		Node *ptr;
		ptr = new Node;
		ptr->booking_status = 0;
		ptr->seat_num = i;
		tail->next = ptr;
		ptr->prev = tail;
		tail = ptr;
		tail->next = head;
		head->prev = tail;
	}
}

void Cinemax::Display(){
	cout<<"\n\n-----------------------------------------"<<endl;
	cout<<"----------ALL EYES HERE PLEASE!!---------"<<endl;
	cout<<"-----------------------------------------"<<endl<<endl<<endl;
	Node* temp;
	temp = head;
	string free = 	":___:";
	string booked = ":_X_:";
	int b = 0;
	int f = 0;
	while(temp->next!=head){
		if(temp->booking_status==0){
			f++;
			if(temp->seat_num%7==0){
				cout<<free<<endl;
			} else {
				cout<<free<<" ";
			}
		} else {
			b++;
			if(temp->seat_num%7==0){
				cout<<booked<<endl;
			} else {
				cout<<booked<<" ";
			}
		}
		temp = temp->next;
	}
	if(temp->booking_status==0){
		cout<<free<<endl<<endl;
		f++;
	} else {
		cout<<booked<<endl<<endl;
		b++;
	}

	cout<<"Number of seats booked: "<<b<<endl;
	cout<<"Number of seats available: "<<f<<endl;
}

void Cinemax::Book(){
	Node* temp;
	temp = head;
	int num;
	cout<<"\n\nEnter the seat number you wish to book: ";
	cin>>num;
	if((num<1)||(num>70)){
		cout<<"\nWe only have 70 seats, please enter a seat number from 1-70\n"<<endl;
	} else {
		while(temp->seat_num!=num){
				temp = temp->next;
			}
			if(temp->booking_status==0){
				temp->booking_status = 1;
				cout<<"Seat number "<<num<<" booked successfully!\n\n"<<endl;
			} else {
				cout<<"\nUnfortunately this seat is already booked!"<<endl<<"Please check seat matrix for available seats.\n"<<endl;
			}
	}

}

void Cinemax::Cancel(){
	Node* temp;
	temp = head;
	int num;
	cout<<"\n\nEnter the seat number you wish to cancel: ";
	cin>>num;
	if((num<1)||(num>70)){
		cout<<"\nWe only have 70 seats, please enter a seat number from 1-70\n"<<endl;
	} else {
		while(temp->seat_num!=num){
				temp = temp->next;
			}
			if(temp->booking_status==1){
				temp->booking_status = 0;
				cout<<"Seat number "<<num<<" cancelled successfully!\n\n"<<endl;
			} else {
				cout<<"\nThis seat is not yet booked!\n"<<endl;
			}
	}
}

int main(){
	Cinemax c;
	c.Create();
	char choice = 'y';
	while(choice=='y'){
		int n;
		cout<<"\n\nWhat do you wish to do?: "<<endl;
		cout<<"1 -- Display the seat matrix \n2 -- Book a seat \n3 -- Cancel a seat"<<endl;
		cout<<"Enter your choice: ";
		cin>>n;

		switch(n){
		case 1: c.Display();
		break;
		case 2: c.Book();
		break;
		case 3: c.Cancel();
		break;
		default: cout<<"\nPlease enter a valid choice!\n"<<endl;
		}
		cout<<"Do you wish to continue? (y/n)"<<endl;
		char d;
		cin>>d;
		choice = d;
	}
	return 0;
}
