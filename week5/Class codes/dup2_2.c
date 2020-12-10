#include <stdio.h>
#include <stdlib.h> 
#include <unistd.h>
#include <sys/types.h> 
#include <sys/stat.h> 
#include <fcntl.h>

int main(void) 
{ 
	int number1, number2, sum;
	int input_fds = open("./input.txt", O_RDONLY);
	int output_fds = open("./output.txt", O_WRONLY);

	dup2(input_fds, STDIN_FILENO); //0
	dup2(output_fds, STDOUT_FILENO); //1

	scanf("%d %d", &number1, &number2);
	sum = number1 + number2;

	printf("%d + %d = %d\n", number1, number2, sum);
	
	return EXIT_SUCCESS;
}