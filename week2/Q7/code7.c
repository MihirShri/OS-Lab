#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>

int main()
{
	pid_t pid;
	printf("1 --> 1 & 2\n");
	pid = fork();
	if (pid == 0)
	{
		pid_t pid1;
		printf("2 --> 2 & 4\n");
		pid1 = fork();

		if (pid1 == 0)
		{
			printf("4 --> 4 & 8\n");
			fork();
		}

		else if (pid1 > 0)
		{
			printf("2 --> 2 & 5\n2 --> 2 & 6\n5 --> 9\n");
			fork();
			fork();
		}
	}

	else if (pid > 0)
	{
		pid_t pid2;
		printf("1 --> 1 & 3\n");
		pid2 = fork();

		if (pid2 == 0)
		{
			printf("3 --> 3 & 7\n");
			fork();
		}
	}

	return 0;
}
