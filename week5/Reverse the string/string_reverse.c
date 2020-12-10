#include <stdio.h>
#include <unistd.h>

#define R_END 0
#define W_END 1

int main(int argc, char const *argv[])
{
	int fd1[2], fd2[2];
	int returnstatus1, returnstatus2;
	int pid;
	char pipe1msg[9] = "MihirShri";
	char pipe2msg[9];
	char readmsg[9];

	returnstatus1 = pipe(fd1);

	if (returnstatus1 == -1)
	{
		printf("Unable to create Pipe 1\n");
		return 1;
	}

	returnstatus2 = pipe(fd2);

	if (returnstatus2 == -1)
	{
		printf("Unable to create Pipe 2\n");
		return 1;
	}

	pid = fork();

	if (pid > 0)
	{
		close(fd1[R_END]);
		close(fd2[W_END]);

		printf("Parent writing to pipe 1. Message sent to child is - %s\n\n", pipe1msg);

		write(fd1[W_END], pipe1msg, sizeof(pipe1msg)+1);

		read(fd2[R_END], readmsg, sizeof(readmsg));

		printf("Parent read from pipe 2. Message read from child is - %s\n", readmsg);
	}

	else
	{
		close(fd1[W_END]);
		close(fd2[R_END]);

		read(fd1[R_END], readmsg, sizeof(readmsg));

		int j=0;
		int i=sizeof(readmsg)/sizeof(readmsg[0]) -1;

		for(;i>=0;i--)
		{
			pipe2msg[j] = readmsg[i];
			j++;
		}

		write(fd2[W_END], pipe2msg, sizeof(pipe2msg)+1);

	}

	return 0;
}
