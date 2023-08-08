#include <stdio.h>

int linearSearch(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i; // Return the index if target is found
        }
    }
    return -1; // Return -1 if target is not found
}

int main() {
    int arr[] = {8, 2, 5, 9, 3};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 9;

    int result = linearSearch(arr, size, target);

    if (result == -1) {
        printf("Element not found\n");
    } else {
        printf("Element found at index %d\n", result);
    }

    return 0;
}