#include <iostream>
using namespace std;

class Node{
public:
	int is_booked;
	int start, end;
	Node* next;
};

class Clinic{
	int st, en;
public:
	Node* head;
	Clinic(){
		cout<<"All times displayed are in 24 hour format\n \n";
		int a, b;
		label:
		cout<<"Enter start time of your clinic: ";
		cin>>a;
		cout<<"Enter end time of your clinic: ";
		cin>>b;
		if(b<a){
			cout<<"Please enter a valid end time!\n"<<endl;
			goto label;
		}
		st = a;
		en = b;
		head = NULL;
	}
	void create();
	void book();
	void cancel();
	void sort();
	void display();
};

void Clinic::create(){
	int i, n;
	Node* temp, * last;
	n = en-st;
	for(i=0; i<n; i++){
		temp = new Node;
		temp->start = st+i;
		temp->end = st+1+i;
		temp->is_booked = 0;
		temp->next = NULL;

		if(head == NULL){
			head = temp;
			last = head;
		} else {
			last->next = temp;
			last = last->next;
		}
	}
}

void Clinic::book(){
	int hr;
	Node* temp;
	cout<<"\n \nWe have 1 hr slots at this clinic\n";
	lab:
	cout<<"Please enter start time for your slot: ";
	cin>>hr;
	if((hr>=en)||(hr<st)){
		cout<<"Invalid appointment slot!\n\n";
		goto lab;
	}
	temp = head;

	while(temp!=NULL){
		if(hr == temp->start){
			if(temp->is_booked == 0){
				cout<<"\nAppointment booked for slot "<<temp->start<<" to "<<temp->end<<endl;
				temp->is_booked = 1;
			} else {
				cout<<"This slot is already booked!"<<endl;
			}
		}
		temp = temp->next;
	}
}

void Clinic::display(){
	int cnt = 1;
	Node * temp;
	cout<<"\n \n*******Appointment Schedule*******\n"<<endl;
	temp = head;
	while(temp!=NULL){
		cout<<cnt<<". "<<temp->start<<" to "<<temp->end<<" -> ";
		if(temp->is_booked==0){
			cout<<"--Available--"<<endl;
		} else {
			cout<<"---Booked---"<<endl;
		}

		temp = temp->next;
		cnt++;
	}
}

void Clinic::cancel(){
	int hrb;
		Node* temp;
		lab:
		cout<<"\nPlease enter start time for your slot: ";
		cin>>hrb;
		if((hrb>=en)||(hrb<st)){
			cout<<"Invalid appointment slot!\n\n";
			goto lab;
		}
		temp = head;

		while(temp!=NULL){
			if(hrb == temp->start){
				if(temp->is_booked == 1){
					cout<<"\nAppointment cancelled for slot "<<temp->start<<" to "<<temp->end<<endl;
					temp->is_booked = 0;
				} else {
					cout<<"\nThis slot hasn't been booked yet!"<<endl;
				}
			}
			temp = temp->next;
		}
}

int main(){
	Clinic c;
	c.create();
	char check;
	check = 'y';
	while(check=='y'){
		int num;
		cout<<"\n \n1. Book a slot \n2. Cancel a slot \n3. Display the bookings\n";
		cout<<"What do you wish to do?: ";
		cin>>num;
		switch(num){
		case 1: c.book();
		break;
		case 2: c.cancel();
		break;
		case 3: c.display();
		break;
		default: cout<<"Wrong choice!"<<endl;
		}
		char s;
		cout<<"Do you wish to continue? (y or n): ";
		cin>>s;
		check = s;
	}
	return 0;
}
