#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void bin_search(int a[], int n, int key)
{
	for (int i = 0; i < n/2; i++)
	{
	    for (int j = 0; j < n/2; j++)
	    {
	    	if (a[j] > a[i])
	      	{
		        int tmp = a[i];
		        a[i] = a[j];
		        a[j] = tmp;
	      	}  
	    }
	}

	int mid, beg = 0, end = n/2-1, flag = 0;
	while(beg<=end)
	{
		mid=(beg+end)/2;

		if(a[mid]==key)
		{
			flag += 1;
			break;
		}

		else if(a[mid]<key)
	    	beg=mid+1;

		else
	    	end=mid-1;
	}

	int i = mid, j = mid;
	if (flag == 1)
	{
		while (a[i] == a[i-1] && i >= 0)
		{
			flag += 1;
			i--;
		}

		while (a[j] == a[j+1] && j <= n/2 - 1)
		{
			flag += 1;
			j++;
		}

		printf("Element %d found %d times in the first half of the array\n", key, flag);
	}

	else
		printf("Element %d not found in the first half of the array\n", key);
 }

 int main()
{
	int n, a[100], key;

	printf("Enter the size of the array: ");
	scanf("%d", &n);

	// Store the value of n in a file
	FILE *fptr;
	fptr = fopen("n.txt", "w");
	putw(n, fptr);

	printf("Enter the array elements: ");

	for (int i = 0; i < n; ++i)
	{
		scanf ("%d", &a[i]);
		putw(a[i], fptr);
	}

	printf("Enter the element to search: ");
	scanf ("%d", &key);
	putw(key, fptr);

	bin_search(a, n, key);

	fclose(fptr);

	return 0;
}
