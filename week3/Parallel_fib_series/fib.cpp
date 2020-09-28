#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string>
#include <bits/stdc++.h>
using namespace std;
 
int fib (int n) 
{ 
    
	if(n <= 2)
		return 1;

   	else
   	{
   		pid_t pid = vfork();

   		long int fib_0, fib_1;

   		if(pid == 0)
   		{
   			fib_0 = fib(n-2);
   			_exit(0);
   		}

   		else if(pid > 0)
   			fib_1 = fib(n-1);

   		wait(NULL);

   		return fib_1 + fib_0;
   }
} 

int main() 
{
    int i, n;
    
    cout << "Enter the number of terms (n): ";
    cin >> n;
    
    for(int i = 1; i <= n; i++)
    	cout << fib(i) << " ";

    cout << endl;

    return 0;

}