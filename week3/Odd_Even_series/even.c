#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void even_series(int n)
{
	printf("\nEven series till %d:\n", n);
	for (int i = 0; i <= n; i+=2)
		printf("%d ", i);

	printf("\n\n");
}

int main()
{
	int n;

	printf("Enter the value of n: ");
	scanf("%d", &n);
	even_series(n);

	// Store the value of n in a file
	FILE *fptr;
	fptr = fopen("n.txt", "w");
	putw(n, fptr);
	fclose(fptr);

	return 0;
}