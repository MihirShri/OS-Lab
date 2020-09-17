# include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
int main ()
{
	pid_t ChildPid;
	ChildPid = fork();

	if (ChildPid == 0)
	{
		printf("Hello, I'm Child!\n");
		exit(0);
	}

	else if (ChildPid < 0)
	{
		printf("Error: Frok failed!\n");
	}

	else
	{
		int ReturnStatus;
		waitpid(ChildPid, &ReturnStatus, 0);

		if (ReturnStatus == 0)
			printf("The child process terminated normally.\n");

		else if (ReturnStatus == 1)
			printf("The child process terminated with an error!\n");
	}

	return 0;
}
