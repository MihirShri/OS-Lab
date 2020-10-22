// C program to implement concurrent merge sort  
#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <sys/wait.h>

void insertionSort(int arr[], int n); 
void merge(int a[], int l1, int h1, int h2); 

void mergeSort(int a[], int l, int h) 
{ 
	int i, len=(h-l+1); 

	// Using insertion sort for small sized array 
	if (len<=5) 
	{ 
		insertionSort(a+l, len); 
		return; 
	} 

	pid_t lpid,rpid; 
	lpid = vfork(); 
	if (lpid<0) 
	{ 
		// Lchild proc not created 
		perror("Left Child Proc. not created\n"); 
		_exit(-1); 
	} 
	else if (lpid==0) 
	{ 
		mergeSort(a,l,l+len/2-1); 
		_exit(0); 
	} 
	else
	{ 
		rpid = vfork(); 
		if (rpid<0) 
		{ 
			// Rchild proc not created 
			perror("Right Child Proc. not created\n"); 
			_exit(-1); 
		} 
		else if(rpid==0) 
		{ 
			mergeSort(a,l+len/2,h); 
			_exit(0); 
		} 
	} 

	int status; 

	// Wait for child processes to finish 
	waitpid(lpid, &status, 0); 
	waitpid(rpid, &status, 0); 

	// Merge the sorted subarrays 
	merge(a, l, l+len/2-1, h); 

} 

/* Function to sort an array using insertion sort*/
void insertionSort(int arr[], int n) 
{ 
int i, key, j; 
for (i = 1; i < n; i++) 
{ 
	key = arr[i]; 
	j = i-1; 

	/* Move elements of arr[0..i-1], that are 
		greater than key, to one position ahead 
		of their current position */
	while (j >= 0 && arr[j] > key) 
	{ 
		arr[j+1] = arr[j]; 
		j = j-1; 
	} 
	arr[j+1] = key; 
} 
} 

// Method to merge sorted subarrays 
void merge(int a[], int l1, int h1, int h2) 
{ 
	// We can directly copy the sorted elements 
	// in the final array, no need for a temporary 
	// sorted array. 
	int count=h2-l1+1; 
	int sorted[count]; 
	int i=l1, k=h1+1, m=0; 
	while (i<=h1 && k<=h2) 
	{ 
		if (a[i]<a[k]) 
			sorted[m++]=a[i++]; 
		else if (a[k]<a[i]) 
			sorted[m++]=a[k++]; 
		else if (a[i]==a[k]) 
		{ 
			sorted[m++]=a[i++]; 
			sorted[m++]=a[k++]; 
		} 
	} 

	while (i<=h1) 
		sorted[m++]=a[i++]; 

	while (k<=h2) 
		sorted[m++]=a[k++]; 

	int arr_count = l1; 
	for (i=0; i<count; i++,l1++) 
		a[l1] = sorted[i]; 

} 

// To check if array is actually sorted or not 
void isSorted(int arr[], int len) 
{ 
	if (len==1) 
	{ 
		printf("\nSorting Done Successfully\n"); 
		return; 
	} 

	int i; 
	for (i=1; i<len; i++) 
	{ 
		if (arr[i]<arr[i-1]) 
		{ 
			printf("\nSorting Not Done\n"); 
			return; 
		} 
	} 
	printf("\nSorting Done Successfully\n"); 
	return; 
} 

// Driver code 
int main() 
{ 
	int length = 20;

	/*printf("Enter No of elements of Array: "); 
	scanf("%d",&length);*/

	int shm_array[] = {46, 52, 13, 29, 48, 90, 2, 31, 78, 1, 55, 5, 87, 65, 7, 70, 22, 15, 17, 4};

	printf("Elements of the array are: ");

	for (int i = 0; i < length; ++i)
	{
		printf("%d ", shm_array[i]);
	}

	// Sort the created array 
	mergeSort(shm_array, 0, length-1); 

	// Check if array is sorted or not 
	isSorted(shm_array, length); 

	for (int i = 0; i < length; i++)
		printf("%d ", shm_array[i]);

	printf("\n");

	return 0; 
} 
