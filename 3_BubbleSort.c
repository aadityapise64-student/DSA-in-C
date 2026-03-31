#include <stdio.h>

// Function to perform Bubble Sort
// Bubble Sort compares adjacent elements and swaps them if they are in the wrong order.
// This process is repeated until the array is fully sorted.
void bubbleSort(int arr[], int n) {
    int i, j, temp;
    // Outer loop for passes through the array
    for (i = 0; i < n - 1; i++) {
        // Inner loop for comparing adjacent elements
        // The largest element "bubbles up" to the end of the array in each pass
        for (j = 0; j < n - i - 1; j++) {
            // Swap if the element found is greater than the next element
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Helper function to print an array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    // Unsorted array
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    printf("Unsorted array: \n");
    printArray(arr, n);
    
    // Call the sort function
    bubbleSort(arr, n);
    
    printf("Sorted array: \n");
    printArray(arr, n);
    
    return 0;
}
