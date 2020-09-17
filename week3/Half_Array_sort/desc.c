#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int desc(int a[], int n)
{
	for (int i = n/2; i < n; i++)
	{
	    for (int j = n/2; j < n; j++)
	    {
	    	if (a[j] < a[i])
	      	{
		        int tmp = a[i];
		        a[i] = a[j];
		        a[j] = tmp;
	      	}  
	    }
	}

	for (int i = n/2; i < n; i++)
		printf("%d ", a[i]);
 }

 int main()
{
	int n, a[100];

	// Read the value of n from the file
	FILE *fptr;
	fptr = fopen("n.txt", "r");
	n = getw(fptr);

	for (int i = 0; i < n; ++i)
	{
		a[i] = getw(fptr);
	}

	fclose(fptr);
	
	printf("\nSecond half in descending order:\n");
	desc(a, n);
	printf("\n");

	return 0;
}
