#include<iostream>
using namespace std;

int main (){
	//creating the static array .. rember the syntax of it.
	int array[4]= {1,2,3,4}; // size is fixed and can not be changeable at run time.
	
	cout<<"Static Array."<<endl;
	cout<<"Printing using index."<<endl;
	for(int x=0;x<4;x++){
		cout<<"\t"<<array[x];
	}
	
	cout<<endl;
	cout<<"Printing using pointer."<<endl;
	int*ptr= array;
	for(int x=0;x<4;x++){
		cout<<"\t"<<*ptr++;
	}
	//delete [] array ;// error, because we can not free the size from stack
//	array[6]= {1,2,3,4,5,6}; //Error: We can not change the size of static array if it already defined.
// we can not change the size of the static aray at run time.
	
	cout<<endl;
	cout<<"\n\nDynamic Array."<<endl; 
   int n=4;
   //Creating a dynamic Array, remember the systex of it.
   int *array2 = new int [n]; // size is not fixed and changeable at run time.
   array2[0]= 1;
   array2[1]= 2;
   array2[2]= 3;
   array2[3]= 4;
	cout<<endl;
	cout<<"Printing using index."<<endl;
	for(int x=0;x<4;x++){
		cout<<"\t"<<array2[x];
	}
	
	cout<<endl;
		cout<<"Printing using pointer."<<endl;
	int*ptr2= array2;
	for(int x=0;x<4;x++){
		cout<<"\t"<<*ptr2++;
	}
	cout<<endl<<endl<<endl;
	delete array2; //Size is remove at runtime
	 cout<<"Chnaging the size of dynamic array at runtime... :)";
	// Changing the size of the array to 10.. at runtime 
	array2 = new int [10]; // Array size is now change to 10 at runtime
   array2[0]= 1;
   array2[1]= 2;
   array2[2]= 3;
   array2[3]= 4;
   array2[4]= 5;
   array2[5]= 6;
   array2[6]= 7;
   array2[7]= 8;
   cout<<endl;
	cout<<"Printing using index."<<endl;
	for(int x=0;x<7;x++){
		cout<<"\t"<<array2[x];
	}
	// free the memory/ heap
	delete [] array2;
	return 0;
}
