#include <stdio.h>

// Function to perform linear search
// Linear search goes through each element in the array one by one
// and compares it with the element we are looking for.
int linearSearch(int arr[], int size, int target) {
    // Loop through the entire array
    for (int i = 0; i < size; i++) {
        // If the current element matches the target, return its index
        if (arr[i] == target) {
            return i; 
        }
    }
    // If the loop finishes and target is not found, return -1
    return -1;
}

int main() {
    // Basic array of integers
    int arr[] = {10, 23, 45, 70, 11, 15};
    int size = sizeof(arr) / sizeof(arr[0]); // Calculate the number of elements in the array
    
    int target = 70; // The number we want to find
    
    // Call the linearSearch function
    int result = linearSearch(arr, size, target);
    
    // Print the result
    if (result != -1) {
        printf("Element %d found at index: %d\n", target, result);
    } else {
        printf("Element %d not found in the array.\n", target);
    }
    
    return 0;
}
