#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>

int main ()
{
	pid_t pid; // this is to use the pid data type – relevant headers above
	int n;

	printf("Enter the value of n: ");
	scanf("%d", &n);

	int num = n;

	for (int i = 1; i <= n; i++)
	{
		pid = vfork();
		int sum = 0, k=i;

		if (pid == 0)
		{
			int d;
			while (k > 0)
			{
				d = k % 10;
				sum += d*d*d;
				k /= 10;
			}
			pid = 1;
		}

		if (pid > 0)
		{
			wait (NULL); // parent waits for the child to complete execution.

			if (i == sum)
				printf("%d\n", i);
		}

	}
	exit(0);
		
	return 0;
}
