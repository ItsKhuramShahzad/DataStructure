#include<iostream>
using namespace std;
int main (){
	int A[]= {1, -3};
	int size= sizeof(A)/sizeof(A[0]);
	
	int c=1;
	int a= size; 
	int b= size; 
	bool flag= true;
	while(a>=0)
	{
		b= size;
		while(b>=0)
		{
		  if(c==A[b])
    		{
    			flag= false;
    			break;
			}
          b--;
        }
        if (flag)
    	{	
		  cout<< c<<endl;
		break;
		}
        a--;
        c++;
		flag= true;
	}
	return 0;
}
