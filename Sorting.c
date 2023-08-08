#include <stdio.h>

// Bubble Sort
void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                // Swap arr[j] and arr[j+1]
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Selection Sort
void selectionSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {

        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[i])
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

// Insertion Sort
void insertionSort(int arr[], int n)
{
    int i, j;
    for (i = 1; i < n; i++)
        for (j = 0; j < i; j++)
            if (arr[j] > arr[i])
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
}

int main()
{
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    bubbleSort(arr, n);
    printf("\n\nBubble sorted array: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    int arr2[] = {64, 34, 25, 12, 22, 11, 90};
    selectionSort(arr2, n);
    printf("\n\nSelection sorted array: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr2[i]);
    }

    int arr3[] = {64, 34, 25, 12, 22, 11, 90};
    insertionSort(arr3, n);
    printf("\n\nInsertion sorted array: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr3[i]);
    }

    return 0;
}