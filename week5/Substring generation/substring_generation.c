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
	char pipe2msg[4];
	char readmsg[9];
	char readmsg2[4];

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

		read(fd2[R_END], readmsg2, sizeof(readmsg2));

		printf("Parent read from pipe 2. Message read from child is - %s\n", readmsg2);
	}

	else
	{
		close(fd1[W_END]);
		close(fd2[R_END]);

		read(fd1[R_END], readmsg, sizeof(readmsg));

		pipe2msg[0] = readmsg[4];
		pipe2msg[1] = readmsg[5];
		pipe2msg[2] = readmsg[6];

		write(fd2[W_END], pipe2msg, sizeof(pipe2msg)+1);

	}

	return 0;
}
