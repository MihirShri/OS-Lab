#include <stdio.h>
#include <unistd.h>

#define R_END 0
#define W_END 1

int main(int argc, char const *argv[])
{
	int fd1[2], fd2[2];
	int returnstatus1, returnstatus2;
	int pid;
	char pipe1msg[10] = "Mihir";
	char pipe2msg[10] = "Shri";
	char readmsg[10];

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
		close(fd1[W_END]);
		close(fd2[R_END]);

		printf("Parent string is - %s\n", pipe1msg);

		read(fd1[R_END], readmsg, sizeof(readmsg));

		for (int i = 0; i < 4; i++)
			pipe1msg[i+5] = readmsg[i];

		write(fd2[W_END], pipe1msg, sizeof(pipe1msg)+1);

	}

	else
	{
		close(fd1[R_END]);
		close(fd2[W_END]);

		printf("Chile writing to pipe 1. Message sent to parent is - %s\n", pipe2msg);

		write(fd1[W_END], pipe2msg, sizeof(pipe2msg)+1);

		read(fd2[R_END], readmsg, sizeof(readmsg));
		
		printf("Child read from pipe 2. Message received from parent is - %s\n", readmsg);

	}

	return 0;
}
