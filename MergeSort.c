#include <stdio.h>

void merge(int a[], int lb, int mid, int ub);

void merge(int a[], int lb, int mid, int ub)
{
    int i = lb, j = mid + 1, k = 0;
    int c[100];
    while (i <= mid && j <= ub)
    {
        if (a[i] < a[j])
        {
            c[k] = a[i];
            i++;
        }
        else if (a[i] > a[j])
        {
            c[k] = a[j];
            j++;
        }
        else
        {
            c[k++] = a[i];
            c[k] = a[j];
        }
        k++;
    }
    while (i <= lb)
    {
        c[k++] = a[i++];
    }
    while (j <= ub)
    {
        c[k++] = a[j++];
    }

    // Copy the merged elements back to the original array
    for (i = 0; i < k; i++)
    {
        a[lb + i] = c[i];
    }
}

int main()
{
    int i;

    int arr[] = {12, 11, 13, 5, 6, 7};
    int arr_size = sizeof(arr) / sizeof(arr[0]);

    printf("Given array is: ");
    for (i = 0; i < arr_size; i++)
    {
        printf("%d ", arr[i]);
    }

    merge(arr, 0, arr_size / 2, arr_size - 1);

    printf("\nSorted array is: ");
    for (i = 0; i < arr_size; i++)
    {
        printf("%d ", arr[i]);
    }
    
    printf("\n");
    return 0;
}