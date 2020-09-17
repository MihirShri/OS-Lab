#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
	int n, sum;

	// Read the value of n from the file
	FILE *fptr;
	fptr = fopen("n.txt", "r");
	n = getw(fptr);

	printf("The following are the Armstrong numbers between 1 to %d:\n", n);

	for (int i = 1; i <= n; i++)
	{
		sum = getw(fptr);
		if (i == sum)
			printf("%d\n", i);
	}
	
	fclose(fptr);

	return 0;
}