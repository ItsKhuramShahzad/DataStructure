// Double Linked List Implementation
//KS.
#include<iostream>
using namespace std;

class node {
	public:
		node *next;
		node * previous;
		int data;

		node(int val) {
			data= val;
			next= previous=NULL;
		}

};

class DoubleLinkedList {
	private:
		node *head;
		int length;

	public:
		DoubleLinkedList() {
			head= NULL;
			length=0;
		}
		// Insertion in Double Linklist

		void insert(int val);
		void insertAt(int val, int pos);
		// What about insert through Recursion.... ???

		// Printing
		void printing(int order);
		void traverseDesending();
		void traverseAssending();
		void travereUsingRecurison(node * curr);

		// Removing Node from List
		void remove(int key);
		void removeAt(int pos);
		// What about removing node through Recursion.... ???

		//Combine two List
		void concatenate(DoubleLinkedList l1,DoubleLinkedList l2);
		int size() {
			return length;
		}
		node * getHead() {
			node * curr= head;
			return curr;
		}

};

int main() {
	DoubleLinkedList list1, list2;


	list1.insertAt(1, 1);
	list1.insertAt(2, 2);
	list1.insertAt(3, 3);
	list1.insertAt(4, 4);
	
	list2.insertAt(5, 1);
	list2.insertAt(6, 2);
	list2.insertAt(7, 3);
	list2.insertAt(8, 4);
	//list1.removeAt(4);
	list1.concatenate(list1, list2);
	list1.traverseDesending();

	cout<< endl<< " List size: "<<list1.size()<<endl;
	return 0;
}

void DoubleLinkedList:: concatenate(DoubleLinkedList l1,DoubleLinkedList l2) {

	node *l1_curr= l1.getHead();
	
	while (l1_curr->next!=NULL)
	{
		l1_curr= l1_curr->next;
	}
	node *l2_curr= l2.getHead();
	l1_curr->next =l2.getHead();
	l2_curr->previous= l1_curr;
     
	}
void DoubleLinkedList::  removeAt(int pos) {
	node *curr = head;
	if(head == NULL) {
		cout << "LIST is empty " << endl;
	}
	if(pos == 1) {  // for deleting head

		head = curr->next;
		head->previous = NULL;
		delete curr;
		length--;
	} else {   // for deleting any other node
		node *temp = NULL;
		for(int i = 0; i < pos-1; i++) {
			temp = curr;
			curr = curr->next;
		}
		temp->next = curr->next;

		if(curr->next != NULL)
			curr->next->previous = temp;

		delete curr;
		length--;
	}
}

void DoubleLinkedList::  remove(int key) {
	node* curr= head;
	if (curr==NULL)
		cout<<"List is Empty";
	else

		while(curr!=NULL) {
			// when list have only one node;
			if (curr->data==key &curr->next==NULL && curr->previous==NULL) {
				delete curr;
				length--;
				return;
			} // when head is going to be deleted
			else if (curr->data==key &curr->next!=NULL && curr->previous ==NULL) {
				head= curr->next;
				curr->next->previous= NULL;
				curr->next =NULL;
				delete curr;
				length--;
				return;
			}
			// when last node is going to be deleted
			else if (curr->data==key &curr->next==NULL && curr->previous !=NULL) {
				curr->previous->next =NULL;
				curr->previous =NULL;
				delete curr;
				length--;
				return;

			}

			else if (curr->data==key &curr->next!=NULL && curr->previous!=NULL) {
				curr->previous->next= curr->next;
				curr->next->previous= curr->previous;
				delete curr;
				length--;
				return;
			}
			curr= curr->next;
		}
	cout<<" The node having value: "<< key <<" dose not exist "<<endl;
}
void DoubleLinkedList:: travereUsingRecurison(node * curr) {

	if (curr==NULL)
		return ;
	else {
		cout<< curr->data<<endl;
		travereUsingRecurison(curr->next);
	}
}

void DoubleLinkedList::insert(int val) {
	node *t = new node (val);
	if (head==NULL) { // Head is Empty
		head= t;
		length ++;
	} else {

		node * curr= head;
		while (curr->next!=NULL) {
			curr= curr->next;
		}

		curr->next= t;
		t->previous= curr;
		length ++;
	}

}
void DoubleLinkedList::insertAt(int val, int pos) {
	if(pos<1 || pos>length+1) {
		cout<<"Invalid position."<<endl;
		return;
	}
	node *t = new node (val);

	if(pos==1) { // When we want to inserting new node before  head..
		if (head==NULL) { // Head is Empty
			head= t;
			length ++;
		} else { //head is already exist,  inserting new node before existing head..
			t->next =head;
			head->previous= t;
			head=t;
			length ++;
		}
	}

	else { // position can be in center or in last
		node * curr= head;
		//	cout<<curr->data<< "  here"<<endl;
		for(int i=1; i<pos-1; i++) {
			curr=curr->next;
		}
		//cout<<curr->data<< "  here"<<endl;
		t->next = curr->next;
		t->previous= curr;

		if (curr->next!=NULL) // If its not a Last node
			curr->next->previous= t;
		curr->next= t;
		length ++;
	}
}
void DoubleLinkedList::printing(int order) {
	node *curr=head;
	if(order== 1) {
		while (curr !=NULL) {
			cout<<"Node: "<<curr->data<<endl;
			curr=curr->next;
		}
	} else if (order== 2) {
		if (curr->next ==NULL && curr->previous==NULL) {
			cout<<curr->data;
			return;
		} else {

			while (curr !=NULL) {
				curr=curr->next;
			}

			while (curr->previous !=NULL) {
				cout<<"Node: "<<curr->data<<endl;
				curr=curr->previous;

			}
		}
	}

}

void DoubleLinkedList:: traverseAssending() {
	node *curr=head;
	while(curr!=NULL) {
		cout<<" Node: "<<curr->data<<endl;
		curr= curr->next;
	}
}

void DoubleLinkedList::traverseDesending() {
	node *curr=head;
	while(curr->next!=NULL) {
		curr= curr->next;
	}

	while (curr->previous!=NULL) {
		cout<<" Node: "<<curr->data<<endl;
		curr= curr->previous;
	}
	cout<<" Node: "<<curr->data<<endl;
}
