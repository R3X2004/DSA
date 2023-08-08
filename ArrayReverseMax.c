
#include <stdio.h>

void Input(int arr[], int size);
void Display(int arr[], int size);
int Find_Max(int arr[], int size);
void Reverse(int arr[], int size);

int main()
{
    int arr[100];
    int size;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    Input(arr, size);

    printf("\nOriginal Array:\n");
    Display(arr, size);

    printf("\nLargest element in the array: %d\n", Find_Max(arr, size));

    printf("\nReversed Array:\n");
    Reverse(arr, size);
    Display(arr, size);

    return 0;
}

void Input(int arr[], int size)
{
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }
}

void Display(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
}

int Find_Max(int arr[], int size)
{
    int max = arr[0];
    for (int i = 1; i < size; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    return max;
}

void Reverse(int arr[], int size)
{
    int temp;
    for (int i = 0, j = size - 1; i < j; i++, j--)
    {
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}
