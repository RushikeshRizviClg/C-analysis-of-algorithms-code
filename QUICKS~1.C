/* C implementation QuickSort */
#include<stdio.h>
#include<conio.h>

// A utility function to swap two elements
void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

/* This function takes last element as pivot, places
   the pivot element at its correct position in sorted
    array, and places all smaller (smaller than pivot)
   to left of pivot and all greater elements to right
   of pivot */
int partition (int arr[], int low, int high)
{
    int pivot = arr[high],j,t;    // pivot
    int i = (low - 1);  // Index of smaller element

    for (j = low; j <= high- 1; j++)
    {
	// If current element is smaller than or
	// equal to pivot
	if (arr[j] <= pivot)
	{
	    i++;    // increment index of smaller element
	    t=arr[i];
	    arr[i]=arr[j];
	    arr[j]=t;
//	    swap(&arr[i], &arr[j]);
	}
    }
//    swap(&arr[i + 1], &arr[high]);
    t=arr[i+1];
    arr[i+1]=arr[high];
    arr[high]=t;
    return (i + 1);
}

/* The main function that implements QuickSort
 arr[] --> Array to be sorted,
  low  --> Starting index,
  high  --> Ending index */
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
	/* pi is partitioning index, arr[p] is now
	   at right place */
	int pi = partition(arr, low, high);

	// Separately sort elements before
	// partition and after partition
	quickSort(arr, low, pi - 1);
	quickSort(arr, pi + 1, high);
    }
}



// Driver program to test above functions
void main()
{
    int arr[100],i,n;
      clrscr();
    printf("Enter size of arrary:");
    scanf("%d",&n);
    printf("Enter array element:");
    for (i=0; i<n; i++)
	scanf("%d",&arr[i]);
    printf("\n");


    quickSort(arr, 0, n-1);
    printf("Quick Sorted array: ");
    for (i=0; i < n; i++)
	printf("%d ",arr[i]);
    printf("\n");
    getch();
}