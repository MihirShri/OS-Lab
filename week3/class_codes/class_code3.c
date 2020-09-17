# include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
int main ()
{
	pid_t ChildPid, wpid;
	int status = 0;
	int n = 5;

	printf("Hello, I'm Father!\n\n");

	for (int id = 0; id < n; id++)
	{
		if ((ChildPid = fork()) == 0)
		{
			printf("Hello, I'm child %d\n", id+1);
			exit(0);
		}
	}

	while ((wpid = wait(&status)) > 0);

	printf("\nHello, I'm Father again. All my child processes have ended.\n");

	return 0;
}
