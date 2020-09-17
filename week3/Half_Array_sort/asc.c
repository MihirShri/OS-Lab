#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int asc(int a[], int n)
{
	for (int i = 0; i < n/2; i++)
	{
	    for (int j = 0; j < n/2; j++)
	    {
	    	if (a[j] > a[i])
	      	{
		        int tmp = a[i];
		        a[i] = a[j];
		        a[j] = tmp;
	      	}  
	    }
	}

	for (int i = 0; i < n/2; i++)
		printf("%d ", a[i]);
 }

int main()
{
	int n, a[100];

	printf("Enter the size of the array: ");
	scanf("%d", &n);

	// Store the value of n in a file
	FILE *fptr;
	fptr = fopen("n.txt", "w");
	putw(n, fptr);

	printf("Enter the array elements: ");

	for (int i = 0; i < n; ++i)
	{
		scanf ("%d", &a[i]);
		putw(a[i], fptr);
	}

	printf("\nFirst half in ascending order:\n");
	asc(a, n);
	printf("\n");

	fclose(fptr);

	return 0;
}
