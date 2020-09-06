#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/*A function to print and array*/
void swap(int *xp, int *yp)
{
    int temp = *xp;  
    *xp = *yp;  
    *yp = temp;  
}


// A function which returns 1 if a is smaller than b
int less_than(int a, int b)
{
	return a < b;
}


// A function which returns 1 if a is greater than b
int greater_than(int a,int b)
{
	return a > b;
}


// A function for bubble sort algorithm with function pointer
void bubbleSort(int arr[], int n, int flag)
{
	int (*asc_or_dsc[])(int, int) = {less_than, greater_than};
    	int i, j;
    	for (i = 0; i < n-1; i++)
    		for (j = 0; j < n-i-1; j++)
            		if((*asc_or_dsc[flag])(arr[j], arr[j+1]))
                		swap(&arr[j], &arr[j+1]);
}


// A function to print an array
void printArray(int arr[], int size)
{
    	int i;
    	printf("Sorted array:\n");
    	for (i = 0; i < size; i++)
        	printf("%d ", arr[i]);
    	printf("\n");
}


int main(int argc, char* argv[])
{
	// Convert the required command line arguments from string to integer
	int size = atoi(argv[1]), flag = atoi(argv[2]);
	int a[size];
	
	if (size <= 0)
	{
		printf("Invalid size!\nPlease enter size > 0\n");
		exit(EXIT_FAILURE);
	}
	
	if (flag > 1)
	{
		printf("Invalid choice!\n0 - Descending, 1 - Ascending\n");
		exit(EXIT_FAILURE);
	}
	
	for (int i = 0; i < size; i++)
	{
		a[i] = atoi(argv[i+3]);
	}
	
	bubbleSort(a, size, flag);
		
	printArray(a, size);	
	
	return 0;
}
