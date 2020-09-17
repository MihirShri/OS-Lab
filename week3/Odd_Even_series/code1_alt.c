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
		printf("\nEven series till %d:\n", n);
		for (int i = 0; i <= n; i+=2)
			printf("%d ", i);

		printf("\n\n");
	}

	else
	{
		wait (NULL); // parent waits for the child to complete execution.
		printf("Odd series till %d:\n", n);
		for (int i = 1; i <= n; i+=2)
			printf("%d ", i);

		printf("\n");
	}
	
	return 0;
}
