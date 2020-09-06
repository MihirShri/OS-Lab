#include <stdio.h>

int main()
{
	int pid;
	pid = fork();
	if (pid < 0)
		printf("Fork failed\n");
	else if (pid == 0)
		printf("Child block\n");
	else if (pid > 0)
		printf("Parent block\n");

	return 0;
}
