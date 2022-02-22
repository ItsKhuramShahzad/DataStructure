#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include<stdio.h>
using namespace std;
////////////////////////////////////////////
/*initialization of global variables and dynamic array */
int ts=0;
int *list=new int[ts];
int cs=0; //shows that current size of list is zero
int cl=-1; //shows that list is not created yet

///////////////////////////////////////////
/*declaration of functions */
/*00*/void menu();
/*01*/void create_list();
/*02*/void delete_list();
/*03*/void clear_list();
/*04*/void display_list();
/*05*/void add_item(int);
/*06*/void add_item_by_position(int,int);
/*07*/void remove_item();
/*08*/void remove_item_by_position();
/*09*/void swapp_items(int,int);
/*10*/void swapp_items_by_position(int,int);
/*11*/int find_item(int);
/*12*/int find_item_by_pos(int);
/*13*/void copy_list();
/*14*/void update_item(int,int);
/*15*/void update_item_by_position(int,int);
/*16*/void check_size_of_list();
/*17*/int get_element_by_position(int);
/*18*/int isfull();
/*19*/int isempty();
//////////////////////////////////////////////
void menu() {
	system("pause");
	system("cls");
	int option;
	cout<<"****welcome to list application****\n";
	cout<<"press 0 to exit\n"; //
	cout<<"press 1 to create list\n"; //
	cout<<"press 2 to delete list\n"; //
	cout<<"press 3 to clear list\n"; //
	cout<<"press 4 to display list\n"; //
	cout<<"press 5 to add item in list\n"; //
	cout<<"press 6 to add item at particular position\n"; //
	cout<<"press 7 to remove item from list\n";
	cout<<"press 8 to remove item from particular position\n";
	cout<<"press 9 to swapp items\n";//
	cout<<"press 10 to swapp items by position\n";//
	cout<<"press 11 to finditem in list\n"; //
	cout<<"press 12 to find item by position\n"; //
	cout<<"press 13 to copy list\n";//
	cout<<"press 14 to update item\n"; //
	cout<<"press 15 to update item by position\n"; //
	cout<<"press 16 to check size of list\n"; //
	cout<<"press 17 to getelement\n"; //
	cout<<"enter 18 to check if list is full\n"; //
cout<<"enter 19 to check if list is empty\n"; //
cout<<"enter option:";
cin>>option;
///////////////////////////////////////////////////
switch(option) {
		case 0: {
			exit(0); //built in function to exit from program
		}
		break;
//////////////////////////////////////////////////

		case 1: {
			create_list();
			menu();
		}
		break;
/////////////////////////////////////////////////
		case 2: {
			delete_list();
			menu();
		}
		break;
////////////////////////////////////////////////
		case 3: {
			clear_list();
			menu();
		}
		break;
////////////////////////////////////////////////
		case 4: {
			display_list();
			menu();
		}
		break;
///////////////////////////////////////////////
		case 5: {
			int it;
			if(cl==-1)
				cout<<"list is not created\n";
			else if(isfull()==1)
				cout<<"list is already full\n";
			else
				do {
cout<<"enter item:";
					cin>>it;
					if(find_item(it)==1)
						cout<<"item is already in list\n";
				} while(find_item(it)==1);

			add_item(it);
			cout<<"item added successfully in list\n";
			cs++;
		}
		menu();
		break;
//////////////////////////////////////////////
		case 6: {
			int it,pos;
			if(cl==-1)
				cout<<"list is not created\n";
			else
				do {
cout<<"enter item:";
					cin>>it;
					if(find_item(it)==1)
						cout<<"item is already in list\n";
				} while(find_item(it)==1);
cout<<"enter position: ";
			cin>>pos;
			if(cl==1&&pos<cs) {
				for(int i=cs-1; i>pos-1; i--) {
					list[i+1]=list[i];
				}
				add_item_by_position(it,pos);

cout<<"item added successfully at pos :"<<pos<<endl;
				cs++;
			} else

				if(cl==1&&pos>=cs&&pos<ts)

				{
					list[cs]=it;
					cs++;
				} else
					cout<<"position out of range\n";
		}
		menu();
		break;
/////////////////////////////////////////////
		case 7: {
			if(cs==0)
				cout<<"list is empty\n";
			else if(cl==-1)
				cout<<"list is not created\n";
			else
				remove_item();
			cout<<"item is successfully removed\n";
		}
		menu();
		break;
////////////////////////////////////////////
		case 8: {
			if(cs==0)
				cout<<"list is empty\n";
			else if(cl==-1)
				cout<<"list is not created\n";
			else
				remove_item_by_position();
			cout<<"item successfully deleted\n";
		}
		menu();
		break;
////////////////////////////////////////////
		case 9: {
			int it1,it2;
			if(cs==0)
				cout<<"list is empty\n";
			else if(cl==-1)
				cout<<"list is not created\n";
			else
				do {
cout<<"enter item 1:";
					cin>>it1;
					if(find_item(it1)!=1)
						cout<<"item is not in list\n";
				} while(find_item(it1)!=1);
			do {
cout<<"enter item 2:";
				cin>>it2;
				if(find_item(it1)!=1)
					cout<<"item is not in list\n";
			} while(find_item(it2)!=1);
			swapp_items(it1,it2);
			cout<<"items successfully swapped\n";

		}
		menu();
		break;
///////////////////////////////////////////
		case 10: {
			int pos1,pos2;
			if(cs==0)
				cout<<"list is empty\n";
			else if(cl==-1)
				cout<<"list is not created\n";
			else
				do {
cout<<"enter position 1:";
					cin>>pos1;
				} while(pos1<0||pos1>=cs);
			do {
cout<<"enter position 2:";
				cin>>pos2;
			} while(pos2<0||pos2>=cs);

			swapp_items_by_position(pos1,pos2);
			cout<<"items successfully swapped\n";
		}
		menu();
		break;
////////////////////////////////////////////
		case 11: {
			int it;
			if(cs==0)
				cout<<"list is empty\n";
			else if(cl==-1)
				cout<<"list is not created\n";
			else {
				cout<<"enter item to check its presence in list\n";
				cin>>it;
				find_item(it);
				if(find_item(it)==1) {
					cout<<"item is present in list";
					int i=0;
					while(list[i]!=it) {
						i++;
					}
					cout<<"at position "<<i<<endl;
				} else
					cout<<"item not found\n";
			}
			menu();
		}
		break;
//////////////////////////////////////////////
		case 12: {
			int pos;
			if(cs==0)
				cout<<"list is empty\n";
			else if(cl==-1)
				cout<<"list is not created\n";
			else {
				do {
					cout<<"enter position to find its item\n";
					cin>>pos;
				} while(pos<0||pos>ts);
				find_item_by_pos(pos);
			}
			menu();
		}
		break;
//////////////////////////////////////////////
		case 13: {
			if(cs==0)
				cout<<"list is empty\n";
			else if(cl==-1)
				cout<<"list is not created\n";
			else
				copy_list();
			cout<<"list copied successfully\n";
		}
		menu();
		break;
/////////////////////////////////////////////
		case 14: {
			int it1,it2;
			if(cs==0)
				cout<<"list is empty\n";
			else if(cl==-1)
				cout<<"list is not created\n";
			else {
				do {
					cout<<"enter item to be updated\n";
					cin>>it1;
					if(find_item(it1)!=1)
						cout<<"item is not in list\n";
				} while(find_item(it1)!=1);
				do {
					cout<<"enter new item to be replaced\n";
					cin>>it2;
					if(find_item(it2)==1)
						cout<<"item is already in list\n";
				} while(find_item(it2)==1);
				update_item(it1,it2);
			}
		}
		menu();
		break;
////////////////////////////////////////////
		case 15: {
			int it,pos;
			if(cs==0)
				cout<<"list is empty\n";
			else if(cl==-1)
				cout<<"list is not created\n";
			else {
				do {
cout<<"enter item:";
					cin>>it;
					if(find_item(it)==1)
						cout<<"item already present\n";
				} while(find_item(it)==1);
cout<<"enter position:";
				cin>>pos;
				if(pos<cs)
					update_item_by_position(it,pos);
				else
					cout<<"item at "<<pos<<" is not available to be updated\n";
			}

		}
		menu();
		break;
///////////////////////////////////////////
		case 16: {
			if(cs==0)
				cout<<"list is empty\n";
			else if(cl==-1)
				cout<<"list is not created\n";
			else
				check_size_of_list();

		}
		menu();
		break;
//////////////////////////////////////////
		case 17: {
			int a,pos;
			if(cs==0)
				cout<<"list is empty\n";
			else if(cl==-1)
				cout<<"list is not created\n";
			else
				do {
cout<<"enter position to get from list:";
					cin>>pos;
				} while(pos<0||pos>cs);
			a=get_element_by_position(pos);
cout<<"here is your item from list :"<<a<<endl;
		}
		menu();
		break;
//////////////////////////////////////////
		case 18: {
			if(cs==0)
				cout<<"list is empty\n";
			else if(cl==-1)
				cout<<"list is not created\n";
			else if(isfull()==1)
				cout<<"list is full\n";
			else
				cout<<"list is not full\n";
		}
		menu();
		break;
/////////////////////////////////////////
		case 19: {
			if(cl==-1)
				cout<<"list is not created\n";
			else if(isempty()==1)
				cout<<"list is empty\n";
			else
				cout<<"list is not empty\n";
		}
		menu();
		break;
/////////////////////////////////////////
		default:
			cout<<"invalid option\n";
			menu();
			break;
//////////////////////////////////////////
	} //switch closed
} //funtion closed

/////////////////////////////////////////////////////////////////////////////////////////////////
/*definitions of functions*/
////////////////////////////////////////////////////////////////////////////////////////////////
void create_list() {
	int it;
cout<<"enter total size of list:";
	cin>>ts;
	do {
cout<<"enter current size of list:";
		cin>>cs;
	} while(cs<1 ||cs>=ts);

	int i=0;
	while(i<cs) {

cout<<"enter item:";
		cin>>it;

		if(find_item(it)!=1) {

			list[i]=it;
			i++;
		} else
			cout<<"item already present\n";
	} //while closed
	cl=1;
} //function closed
////////////////////////////////////////////////////////////////////////////////////////////////
int find_item(int it) {
	int i;
	for(i=0; i<ts; i++)

		if(list[i]==it)
			return 1;
}
////////////////////////////////////////////////////////////////////////////////////////////
int find_item_by_pos(int pos)

{
	cout<<"item at position "<<pos<<" is "<< list[pos]<<endl;
	return 1;
}
/////////////////////////////////////////////////////////////////////////////////////////
void display_list() {
	if(cs==0)
		cout<<"list is empty\n";
	else if(cl==-1)
		cout<<"list is not created\n";
	else
		for(int i=0; i<cs; i++)
			cout<<list[i]<<endl;
}
///////////////////////////////////////////////////////////////////////////////////////
void delete_list() {
	if(cl==-1)
		cout<<"list is not created\n";
	else
		cl=-1;
	cout<<"list is successfully deleted\n";
}
////////////////////////////////////////////////////////////////////////////////////
void clear_list() {
	if(cl==-1)
		cout<<"list is not created\n";
	else if(cs==0)
		cout<<"list is already empty\n";
	else
		cs=0;
	cout<<"list is successfully cleared\n";
}
////////////////////////////////////////////////////////////////////////////////////
void add_item(int item) {
	list[cs]=item;
}
//////////////////////////////////////////////////////////////////////////////////
void add_item_by_position(int item,int pos) {
	list[pos]=item;

}
/////////////////////////////////////////////////////////////////////////////////////
int isfull() {
	if(cs==ts)
		return 1;
	else
		return -1;
}
///////////////////////////////////////////////////////////////////////////////////
int isempty() {
	if(cs==0)
		return 1;
	else
		return 0;
}
//////////////////////////////////////////////////////////////////////////////////
void update_item(int it1,int it2) {

	if(find_item(it1)==1) {
		int i;
		for(i=0; list[i]!=it1; i++)
			int a=list[i];
		list[i]=it2;
		cout<<"at"<<i<<"="<<list[i]<<endl;
		cout<<"item successfully updated\n";
	} else
		cout<<it1<<"is not in list\n";
}
////////////////////////////////////////////////////////////////////////////////////
void update_item_by_position(int it,int pos) {
	int a=list[pos];
	list[pos]=it;
	cout<<"item at position "<<pos<<" is successfully updated\n";
cout<<"old item was:"<<a<<endl;
cout<<"new item is :"<<it<<endl;
}
/////////////////////////////////////////////////////////////////////////////////
void check_size_of_list() {

cout<<"current size of list is:"<<cs<<endl;
}
//////////////////////////////////////////////////////////////////////////////
int get_element_by_position(int pos) {

	return list[pos];

}
////////////////////////////////////////////////////////////////////////////////////
void swapp_items(int it1,int it2) {
	int j=0,k=0;

	do {
		j++;
	} while(list[j]!=it1);

	do {
		k++;
	} while(list[k]!=it2);
	int temp=0;
	temp=list[j];
	list[j]=list[k];
	list[k]=temp;
}
///////////////////////////////////////////////////////////////////////////////////
void swapp_items_by_position(int pos1,int pos2) {
	int temp=0;
	temp=list[pos1];
	list[pos1]=list[pos2];
	list[pos2]=temp;
}
//////////////////////////////////////////////////////////////////////////////////
void copy_list() {
	int i,j;
	int *c_list=new int[cs];
	for(i=0; i<cs; i++)
		c_list[i]=list[i];
	cout<<"your copied list is\n";
	for(j=0; j<cs; j++)
		cout<<c_list[j]<<endl;
}
/////////////////////////////////////////////////////////////////////////////////
void remove_item() {
	int it;
	do {
cout<<"enter item to delete from list:";
		cin>>it;
		if(find_item(it)!=1)
			cout<<"item is not in list\n";
	} while(find_item(it)!=1);
	int i=0;
	do {
		i++;
	} while(list[i]!=it);
	int a;
	a=list[i];
	for(int j=i; j<cs-1; j++) {
		list[j]=list[j+1];
	}
	cs--;
}
//////////////////////////////////////////////////////////////////////////////
void remove_item_by_position() {
	int pos;
	do {
cout<<"enter position:";
		cin>>pos;
		if(pos<0||pos>cs)
			cout<<"there is no item at position "<<pos<<endl;
	} while(pos<0||pos>cs);
	int a;
	a=list[pos];
	for(int i=pos; i<cs; i++) {
		list[i]=list[i+1];
	}
	cs--;
}
////////////////////////////////////////////////////////////////////////////////
/* start of main*/
////////////////////////////////////////////////////////////////////////////////////
int main() {
	menu();
	getch();
}
/*end of main */
