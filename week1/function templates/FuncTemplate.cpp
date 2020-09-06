#include <bits/stdc++.h> 
#include <unistd.h>
#include<iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

using namespace std;


// A function which returns 1 if an element a of datatype T is smaller than an element b of datatype T
template<typename T>
int less_than(T a, T b)
{
	return a < b;
}


// A function which returns 1 if an element a of datatype T is greater than an element b of datatype T
template<typename T>
int greater_than(T a,T b)
{
	return a > b;
}


// A bubble sort function which accepts an array of datatype T
template<typename T>
void bubbleSort(T arr[], int n, int flag)
{
	int (*asc_or_dsc[])(T, T) = {less_than, greater_than};
    	size_t i, j;
    	for (i = 0; i < n-1; i++)
    		for (j = 0; j < n-i-1; j++)
            		if((*asc_or_dsc[flag])(arr[j], arr[j+1]))
                	{
                		T temp = arr[j];  
				    arr[j] = arr[j+1];  
				    arr[j+1] = temp;
                 	}
    	cout << "Sorted array:\n";
    	for (size_t i = 0; i < n; i++)
        	cout << arr[i] << " ";
    	cout << endl;
}


// A function to check if the input character is an integer or a floating point number
int isInteger(char* str)
{
	char character;
	for(int i=0;i<strlen(str);++i)
	{
		character = str[i];
		if(character == '.')
			return 0;
	}
	return 1;
}


int main(int argc, char* argv[])
{
	// Convert the required command line arguments from string to integer
	int size = atoi(argv[1]), flag = atoi(argv[2]);
	int integer = 0;
	char a[size];
	int b[size];
	double c[size];
	
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

	// Check if the first element of the array is an alphabet or not
	if (isalpha(argv[3][0]))
	{
		for (int i = 0; i < size; i++)
		{
			a[i] = argv[i+3][0];
		}
		bubbleSort(a, size, flag);
	}
	
	else
	{
		for (int i = 0; i < size; i++)
		{
			// Check if all the elements of the array are integers.
			// Even if a single element is of float type, the array qualifies as a float array		
			if (!isInteger(argv[i+3]))
			{
				integer = 1;
				break;
			}
		}
		
		if (integer == 0)
		{
		
			for (int i = 0; i < size; i++)
			{
				b[i] = atoi(argv[i+3]);
			}
			
			bubbleSort(b, size, flag);
		}
		
		else
		{
			for (int i = 0; i < size; i++)
			{
				c[i] = atof(argv[i+3]);
			}
			
			
			bubbleSort(c, size, flag);
		}
	}
	
	return 0;
}	
	
