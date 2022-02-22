#include<iostream>
#include<conio.h>
#include<process.h>

int length=0;
void create();
void insert();
void deletion();
void search();
void display();
int size();
int a,b[20],n,d,e,f,i;
using namespace std;
int main() {
	int c;

	cout<<"\n Main Menu";
	cout<<"\n 1.Create \n 2.Delete \n 3.Search \n 4.insert \n 5.Display \n 6.Exit";
	do {
		cout<<"\n enter your choice:";
		cin>>c;
		switch(c) {
			case 1:
				create();
				break;
			case 2:
				deletion();
				break;
			case 3:
				search();
				break;
			case 4:
				insert();
				break;
			case 5:
				display();
				break;
			case 6:
				exit(0);
				break;
			default:
				cout<<"The given number is not between 1-5\n";
		}
	} while(c<=6);
	getch();
}
void create() {
	cout<<"\n Enter the number of elements you want to create: ";
	cin>>n;
	length=n;
	cout<<"\nenter the elements\n";
	for(i=0; i<n; i++) {
		cin>>b[i];
	}
}

void deletion() {
	if (length==0)
		cout<<"Array Empty, Please Initilized it first.";
	else {

		cout<<"Enter the number u want to delete \n";
		cin>>d;
		for(i=0; i<n; i++) {
			if(b[i]==d) {
				b[i]=0;
				cout<<d<<" deleted";
				length--;
			}
		}
	}
}
void search() {
	cout<<"Enter the number \n";
	cin>>e;
	for(i=0; i<n; i++) {
		if(b[i]==e) {
			cout<<"Value found the position\n"<<i+1;
		} else {
			cout<<"The Value "<<e<<" found the position\n";
		}

	}
}
void insert() {
	cout<<"\nenter how many number u want to insert: ";
	cin>>f;
	cout<<"\nEnter the elements\n";
	for(i=0; i<f; i++) {
		cin>>b[n++];
		length++;
	}
}
void display() {
	for(i=0; i<n; i++) {
		cout<<"\n"<<b[i];
	}
}

int  size() {
	return length;
}

