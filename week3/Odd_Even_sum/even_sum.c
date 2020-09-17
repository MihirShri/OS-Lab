#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int even_sum(int n)
{
	printf("\nSum of even terms till %d: ", n);
	int sum = 0;
	for (int i = 2; i <= n; i+=2)
		sum += i;

	return sum;
}

int main()
{
	int n;

	printf("Enter the value of n: ");
	scanf("%d", &n);
	printf("%d\n", even_sum(n));

	// Store the value of n in a file
	FILE *fptr;
	fptr = fopen("n.txt", "w");
	putw(n, fptr);
	fclose(fptr);

	return 0;
}