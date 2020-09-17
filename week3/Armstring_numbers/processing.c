#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
	int n, sum;

	FILE *fptr;
	fptr = fopen("n.txt", "w");

	printf("Enter the value of n (range): ");
	scanf("%d", &n);
	putw(n, fptr);

	for (int i = 1; i <= n; i++)
	{
		int d, sum = 0, k = i;
		while (k > 0)
		{
			d = k % 10;
			sum += d*d*d;
			k /= 10;
		}
		
		putw(sum, fptr);
	}

	fclose(fptr);	

	return 0;
}