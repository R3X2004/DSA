#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void QuickSort(int arr[], int start, int end)
{
    if (start >= end)
        return;

    int pivot = arr[start];
    int p = start, c;

    for (c = start ; c <= end; c++)
    {
        if (arr[c] < pivot)
        {
            p++;
            swap(&arr[c], &arr[p]);
        }
    }

    swap(&arr[start], &arr[p]);

    QuickSort(arr, start, p - 1);
    QuickSort(arr, p + 1, end);
}

int main()
{
    int arr[] = {9, 3, 7, 5, 6, 4, 8, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    QuickSort(arr, 0, n - 1);

    printf("\nSorted array:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    
    printf("\n");
    return 0;
}