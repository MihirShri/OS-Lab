#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int odd_sum(int n)
{
	printf("Sum of odd terms till %d: ", n);
	int sum = 0;
	for (int i = 1; i <= n; i+=2)
		sum += i;

	return sum;
}

int main()
{
	int n;

	// Read the value of n from the file
	FILE *fptr;
	fptr = fopen("n.txt", "r");
	n = getw(fptr);
	fclose(fptr);
	
	printf("%d\n", odd_sum(n));

	return 0;
}