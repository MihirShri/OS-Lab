#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void fib(int n)
{
	int f1 = 0, f2 = 1;

	if (n == 0)
		printf(" ");

	else
	{
		for (int i = 1; i <= n; ++i) 
	    {
	        printf("%d ", f1);
	        int f3 = f1 + f2;
	        f1 = f2;
	        f2 = f3;
	    }
	}
}

int main()
{
	int n;

	printf("Enter the value of n: ");
	scanf("%d", &n);
	printf("\nFibonacci series till %d:\n", n);
	fib(n);

	// Store the value of n in a file
	FILE *fptr;
	fptr = fopen("n.txt", "w");
	putw(n, fptr);
	fclose(fptr);

	return 0;
}
