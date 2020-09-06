#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/*A function to swap two integers*/
void swap(int *xp, int *yp)
{
    int temp = *xp;  
    *xp = *yp;  
    *yp = temp;  
}


/*Bubble sort to sort in ascending order*/
void bubbleSortAsc(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n-1; i++)
      
    // Last i elements are already in place
    for (j = 0; j < n-i-1; j++)
        if (arr[j] > arr[j+1])
            swap(&arr[j], &arr[j+1]);
}


/*A function to print and array*/
void printArray(int arr[], int size)
{
    int i;
    printf("Sorted array:\n");
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}


/*Bubble sort to sort in descending order*/
void bubbleSortDsc(int arr[], int n)
{
    int i, j;  
    for (i = 0; i < n-1; i++)
      
    // Last i elements are already in place
    for (j = 0; j < n-i-1; j++)  
        if (arr[j] < arr[j+1])  
            swap(&arr[j], &arr[j+1]);  
}


int main(int argc, char* argv[])
{
	/*Convert the required command line arguments to integer*/
	int size = atoi(argv[1]), flag = atoi(argv[2]);
	int a[size];
	
	/*Convert the array elements from string to integer*/
	for (int i = 0; i < size; i++)
	{
		a[i] = atoi(argv[i+3]);
	}
	
	if (flag == 1)
		bubbleSortAsc(a, size);
	
	else if (flag == 2)
		bubbleSortDsc(a, size);
		
	printArray(a, size);	
	
	return 0;
}
