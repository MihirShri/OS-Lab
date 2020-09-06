#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
int main(int argc, char* argv[])
{
	char ch;
	int count = 0;
	
	/*Error if source file is not provided*/
	if(argc == 1)
	{
		printf("mycopy: missing file operand\n");
		exit(EXIT_FAILURE);
	}
	
	/*Error if source is provided but destination is not provided*/
	if(argc == 2)
	{
		printf("mycopy: missing destination file operand after %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	
	/*Error if too many arguments are passed*/
	if(argc > 3)
	{
		printf("Too many arguments passed!\n");
		exit(EXIT_FAILURE);
	}
	
	/*Open source file in read mode*/
	FILE *source;
	source = fopen(argv[1], "rb");
 
 	/*If source file is not present in that directory, give error*/
	if(source == NULL)
	{
		printf("\nmycopy: cannot stat %s: No such file or directory\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	
	/*Open destination file in write mode*/
	FILE *destination;
	destination = fopen(argv[2], "wb");
	
	/*count the number of characters in source file*/
	while((ch=fgetc(source))!=EOF)
	{
		count++;
	}
 	
 	/*Create a buffer that will hold the content that needs to be copied*/
  	char buffer[count];
  	
  	/*Position the file pointer at the starting of the source file*/
 	fseek(source, 0, SEEK_SET);
 
	/*Transfer data from source file to destination file*/
	fread(buffer, count, 1, source);
	fwrite(buffer, count, 1, destination);
	printf("\nSuccessfully copied\n");
	
	/*Close the file*/
	fclose(source);
 
	exit(EXIT_SUCCESS);
}
