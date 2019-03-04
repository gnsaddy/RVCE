// bubble sort function

void bubbleSort(int arr[], int size)
{
    int i, j, temp;
    for(i = 0; i < size; i++)
    {
        for(j = 0; j < size-i-1; j++)
        {
            if( arr[j] > arr[j+1])
            {
                // swap the elements
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    // print the sorted array
    printf("\nSorted Array using Bubble sort: \n");
    for(i = 0; i < size; i++)
    {
        printf("%d  ", arr[i]);
    }
}

// selection sort

void SelectionSort(int arr[], int size)
{
    int i;
	for(i=0; i<size-1; i++)
	{
		int Imin = i;
		for(int j=i+1; j<size; j++)
		{
			if( arr[j] < arr[Imin] )
			{
				Imin = j;
			}
		}
		int temp = arr[Imin];
		arr[Imin] = arr[i];
		arr[i] = temp;
	}




    printf("\nSorted Array using Selection sort: \n");
    for(int i = 0; i < size; i++)
    {
        printf("%d  ", arr[i]);
    }
}

// Insertion sort

void InsertionSort(int arr[], int size)
{   int i,hole,value;
	for( i=1; i<size; i++)
	{
		 value = arr[i];
		 hole = i;
		while( hole>0 && arr[hole-1]>value)
		{
			arr[hole] = arr[hole-1];
			hole--;
		}
		arr[hole] = value ;
	}
    printf("\nSorted Array using Insertion sort: \n");
    for(int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
}

// Merge sort

// Merges two subarrays of arr[].
// First subarray is arr[l..m]
// Second subarray is arr[m+1..r]
void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;

    /* create temp arrays */
    int L[n1], R[n2];

    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];

    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    /* Copy the remaining elements of L[], if there
       are any */
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    /* Copy the remaining elements of R[], if there
       are any */
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

/* l is for left index and r is right index of the
   sub-array of arr to be sorted */
void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l+(r-l)/2;

        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);

        merge(arr, l, m, r);
    }
}

// quick sort

void quicksort(int list[], int low, int high)
{
    int pivot, i, j, temp;
    if (low < high)
    {
        pivot = low;
        i = low;
        j = high;
        while (i < j)
        {
            while (list[i] <= list[pivot] && i <= high)
            {
                i++;
            }
            while (list[j] > list[pivot] && j >= low)
            {
                j--;
            }
            if (i < j)
            {
                temp = list[i];
                list[i] = list[j];
                list[j] = temp;
            }
        }
        temp = list[j];
        list[j] = list[pivot];
        list[pivot] = temp;
        quicksort(list, low, j - 1);
        quicksort(list, j + 1, high);
    }
}


// heap sort

void heapsort(int a[], int size)
{
    int i, t;
    heapify(a, size);
    for (i = size - 1; i > 0; i--)
    {
        t = a[0];
        a[0] = a[i];
        a[i] = t;
        adjust(a, i);
    }
    for (i = 0; i < size; i++)
        printf("\t%d", a[i]);
    printf("\n");
}
void heapify(int a[], int n)
{
    int k, i, j, item;
    for (k = 1; k < n; k++)
    {
        item = a[k];
        i = k;
        j = (i - 1) / 2;
        while ((i > 0) && (item > a[j]))
        {
            a[i] = a[j];
            i = j;
            j = (i - 1) / 2;
        }
        a[i] = item;
    }
}
void adjust(int a[], int na)
{
    int i, j, item;
    j = 0;
    item = a[j];
    i = 2 * j + 1;
    while (i <= na - 1)
    {
        if (i + 1 <= na - 1)
            if (a[i] < a[i + 1])
                i++;
        if (item < a[i])
        {
            a[j] = a[i];
            j = i;
            i = 2 * j + 1;
        }
        else
            break;
    }
    a[j] = item;
}