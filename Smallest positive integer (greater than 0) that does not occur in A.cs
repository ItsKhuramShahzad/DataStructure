using System;
// you can also use other imports, for example:
// using System.Collections.Generic;

// you can write to stdout for debugging purposes, e.g.
// Console.WriteLine("this is a debug message");

class Solution {
    public int solution(int[] A) {
              // write your code in C# 6.0 with .NET 4.7 (Mono 6.12)
    int size= A.Length;
    int c=1;
	int b= size-1; 
	bool flag= true;
	int res=0;
	while(true)
	{
		b= size-1;
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
		  res = c;
		break;
		}
        c++;
		flag= true;
	}
	return res;
    }
}
