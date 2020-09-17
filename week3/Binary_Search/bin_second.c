#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void bin_search(int a[], int n, int key)
{
	for (int i = n/2; i < n; i++)
	{
	    for (int j = n/2; j < n; j++)
	    {
	    	if (a[j] > a[i])
	      	{
		        int tmp = a[i];
		        a[i] = a[j];
		        a[j] = tmp;
	      	}  
	    }
	}

	int mid, beg = n/2, end = n-1, flag = 0;
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
		while (a[i] == a[i-1] && i >= n/2)
		{
			flag += 1;
			i--;
		}

		while (a[j] == a[j+1] && j <= n-1)
		{
			flag += 1;
			j++;
		}

		printf("Element %d found %d times in the second half of the array\n", key, flag);
	}

	else
		printf("Element %d not found in the second half of the array\n", key);
 }

int main()
{
	int n, a[100];

	// Read the value of n from the file
	FILE *fptr;
	fptr = fopen("n.txt", "r");
	n = getw(fptr);

	for (int i = 0; i < n; ++i)
	{
		a[i] = getw(fptr);
	}

	int key = getw(fptr);

	fclose(fptr);
	
	bin_search(a, n, key);

	return 0;
}