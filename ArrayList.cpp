#include<iostream>
using namespace std;
class ArrayList {
	private:
		int SIZE;
		int length;
		int pos;
		int * Array;
		int * curr;
	public:
		ArrayList() {
			SIZE=10;
			Array= new int[SIZE];
			length=0;
			pos=0;
			curr= Array;
		}
		~ArrayList() {
			delete []Array;
			delete curr;
		}
		void printArray() {
			if(length>0) {
				head();
				for(int x=0; x<length; x++)
					cout<<*curr++<<"\t";
			} else cout<<"Array is Empty"<<endl;
		}
		void InsertElement(int val) {
			if(!IsFull()) {
				head();
				curr= curr +length;
				*curr= val;
				length++;
			} else {
				cout<<"Array is Full"<<endl;
			}
		}
		void InsertAtPos(int val, int pos) {
			if (!IsFull())
			if (pos<=length&&pos>0) {
				tail();
				for (int i=length; i>=pos; i-- ) {
					*(curr+1)= *curr;
					back(); //curr= curr-1;
				}
				next();//curr= curr+1;
				*(curr)= val;
				length++;
			} else if (pos>length && pos<=SIZE) {
				head();
				curr= curr+pos-1;
				*curr= val;
				length++;
			} else
				cout<<"Invalid Position"<<endl;
		}
		void reverseArray() {
			int *p1, *pn, temp;
			p1= Array;
			pn= Array+length-1;
			int val= length/2;
			for (int i=0; i<val; i++) {
				temp= *p1;
				*p1= *pn;
				*pn= temp;
				p1++;
				pn--;
			}
		}
		void deleteElement(int n) {
			if (!IsEmpty()) {
				int *ptr= Array;
				for (int x=0; x<length; x++) {
					if(*ptr==n) {
						int *ptr2= ptr;
						for (int j=x; j<length; j++) {
							ptr2++;
							*ptr= *ptr2;
							ptr++;
						}
						length--;
						break;
					}
					ptr++;
				}
			} else cout<<"Array is Empty, Delete operation failed"<<endl;
		}
		void deleteElementAtPos(int pos) {
			if (!IsEmpty()) {
				if (pos<=SIZE && pos>0){
					head();  //curr= &Array[0]
					curr = curr+pos-1;
					for (int x=0; x<=length-pos; x++){
						*(curr)= *(curr+1);
						next(); //curr= curr+1;
					}
						length--;
				}
			} else cout<<"Array is Empty, Delete operation failed"<<endl;
		}
		bool IsFull() {
			if (length==SIZE)
				return true;
			else return false;
		}
		bool IsEmpty() {
			if (length==0)
				return true;
			else return false;
		}
		void head() {
			curr= Array;
		}
		void tail() {
			curr= Array+length-1;
		}

		void back() {
			curr= curr-1;
		}
		void next() {
			curr= curr+1;
		}
		int Length() {
			return length;
		}
		void emptylist() {
			head();
			for (int x=0; x<SIZE; x++) {
				*curr++=0;
			}
		}
		void sortArray() {
			int *p1;
			int *p2, *temp;
			//sorting - ASCENDING ORDER
			for(int i=0; i<SIZE; i++) {
				p1 = Array+i; 
				for(int j=i+1; j<SIZE; j++) {
					p2 = Array+j;
					if(*p1>*p2) {
						*temp  =*p1;
						*p1=*p2;
						*p2=*temp;
					}
				}
			
			}

		}
		//		void reverseArray() {
//			if(length>0) {
//
//				int * temp= Array+length-1;
//				int * tempA= new int [length-1];
//				int *ptr= tempA;
//
//				for(int x=0; x<length; x++) {
//					*ptr= *temp;
//					ptr++;
//					temp--;
//				}
//				ptr = tempA;
//				temp= Array;
//				for(int x=0; x<length; x++) {
//					*temp= *ptr;
//					ptr++;
//					temp++;
//				}
//			}
//		}
};

int main () {
	ArrayList *obj= new ArrayList();
	
	obj->emptylist();
	obj->InsertElement(1);
	obj->InsertElement(2);
	obj->InsertElement(3);
	obj->InsertElement(4);
	
	obj->printArray();cout<<endl;
	obj->InsertAtPos(99,2);
	
	obj->printArray();cout<<endl;
   obj->deleteElementAtPos(2);
   obj->reverseArray();

	obj->printArray();cout<<endl;
//	obj->InsertElement(1);
//	obj->InsertElement(2);
//	obj->InsertElement(3);
//	obj->InsertElement(4);
//	obj->InsertElement(5);
//	obj->InsertElement(6);
//	obj->InsertElement(7);
//	obj->InsertAtPos(23,1);
//	obj->InsertElement(8);
//	obj->InsertElement(9);
//	obj->InsertElement(10);
//	obj->InsertElement(11);
//	obj->InsertElement(12);
//	obj->InsertElement(13);
	//obj->printArray();
//	obj->deleteElement(1);
//	obj->deleteElement(2);
	cout<<endl;

	//obj->deleteElementAtPos(4);
	
	cout<<endl;
	//obj->emptylist();
   // obj->reverseArrayAdvanced();
	cout<<endl;
	return 0;
}
