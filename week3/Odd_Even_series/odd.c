#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void odd_series(int n)
{
	printf("Odd series till %d:\n", n);
	for (int i = 1; i <= n; i+=2)
		printf("%d ", i);

	printf("\n");
}

int main()
{
	int n;

	// Read the value of n from the file
	FILE *fptr;
	fptr = fopen("n.txt", "r");
	n = getw(fptr);
	fclose(fptr);
	
	odd_series(n);

	return 0;
}