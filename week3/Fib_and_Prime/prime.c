#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int prime(int n)
{
	int c=0;
	for(int i=1;i<=n;i++)
	{
		if(n%i==0)
			c++;
	}

	if(c==2)
		return 1;

	else
		return 0;
}

int main()
{
	int n;

	// Read the value of n from the file
	FILE *fptr;
	fptr = fopen("n.txt", "r");
	n = getw(fptr);
	fclose(fptr);
	
	printf("\n\nPrime numbers till %d:\n", n);

	for (int i = 1; i <= n; i++)
	{
		if (prime(i))
			printf("%d ", i);
	}

	printf("\n");

	return 0;
}
