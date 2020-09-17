#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main ()
{
	pid_t pid; // this is to use the pid data type – relevant headers above
	int n;

	printf("Enter the value of n: ");
	scanf("%d", &n);

	pid = fork();

	if (pid == 0)
	{
		printf("\nSum of even numbers till %d: ", n);
		int sum = 0;
		for (int i = 2; i <= n; i+=2)
			sum += i;

		printf("%d", sum);
		printf("\n");
	}

	else
	{
		wait (NULL); // parent waits for the child to complete execution.
		printf("Sum of odd numbers till %d: ", n);
		int sum = 0;
		for (int i = 1; i <= n; i+=2)
			sum += i;

		printf("%d", sum);
		printf("\n");
	}
	
	return 0;
}