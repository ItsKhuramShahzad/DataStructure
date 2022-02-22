#include<iostream>
using namespace std;

int main (){
    cout<<"Memory Allocated at run time: "<<endl;
	int *p= new int;
	*p= 3;
	

	cout<<"Address: "<<&p<<endl;
	cout<<"Value: "<<*p<<endl;
	
		delete p;
	cout<<"After Memory De Allocation at run time: "<<endl;

	cout<<"Address: "<<&p<<endl;
	cout<<"Value: "<<*p<<endl;
	//since we have notice that delete operator just dereferenc the p pointer to its address.
	//but still variable pointer p is in the memory
}
