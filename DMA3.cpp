/* C++ Dynamic Memory Allocation Example Program */

#include<iostream>
#include<conio.h>
#include<stdlib.h>
using namespace std;
int *rollno;    // declares an integer pointer
float *marks;   // declares a float pointer

int main()
{
   
   int size, i;
   cout<<"How many elements for the array ? ";
   cin>>size;
   rollno = new int[size];    // dynamically allocate rollno array
   marks = new float[size];        // dynamically allocate marks array

   // first check, whether the memory is available or not
   if((!rollno) || (!marks))       // if rollno or marks is null pointer
   {
      cout<<"Out of Memory..!!..Aborting..!!\n";
      cout<<"Press any key to exit..";
      getch();
      exit(1);
   }

   // read values in the array elements
   for(i=0; i<size; i++)
   {
      cout<<"Enter rollno and marks for student "<<(i+1)<<"\n";
      cin>>rollno[i]>>marks[i];
   }

   // now display the array contents
   cout<<"\nRollNo\t\tMarks\n";
   for(i=0; i<size; i++)
   {
      cout<<rollno[i]<<"\t\t"<<marks[i]<<"\n";
   }

   delete[]rollno;    // deallocating rollno array
   delete[]marks;     // deallocating marks array

   getch();
}
