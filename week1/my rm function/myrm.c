#include <stdio.h>
#include<stdlib.h>

int main(int argc, char* argv[])
{
	int status;
	char file_name[50];
	
	/*Error if file name is not provided*/
	if (argc == 1)
	{
		printf("myrm: missing operand");
		exit(EXIT_FAILURE);
	}
	
	/*Error if more than 2 arguments passed*/
	if (argc > 2)
	{
		printf("myrm: Too many arguments!");
		exit(EXIT_FAILURE);
	}

	for (int i=1; i<argc; i++)
	{
		/*Delete the file*/
		status = remove(argv[i]);
		
		/*Check if deletion was successful*/
		if (status == 0)
	  		printf("%s deleted successfully.\n", argv[i]);
		else
		{
	  		printf("Unable to delete the file\n");
	  		perror("Error\n");
		}
		
	}
	
	return 0;
}
