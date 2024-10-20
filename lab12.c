#include <stdio.h>

// Function to perform binary search
int binarySearch(int arr[], int size, int target) {
    int left = 0;  // Start of the search space
    int right = size - 1;  // End of the search space
    
    while (left <= right) {
        int mid = left + (right - left) / 2;  // Calculate the middle index
        
        // Check if the target is at the mid position
        if (arr[mid] == target) {
            return mid;  // Return the index if found
        }
        
        // If target is smaller, search the left half
        if (arr[mid] > target) {
            right = mid - 1;
        }
        // If target is larger, search the right half
        else {
            left = mid + 1;
        }
    }
    
    return -1;  // Return -1 if target is not found
}

// Driver code to test the binary search function
int main() {
    int phonebook[] = {1001, 1010, 1050, 1100, 1200, 1300, 1350};  // Sorted array (phone numbers)
    int size = sizeof(phonebook) / sizeof(phonebook[0]);
    int target = 1100;  // The contact number to search for

    int result = binarySearch(phonebook, size, target);

    if (result != -1) {
        printf("Contact found at index %d\n", result);  // Contact found
    } else {
        printf("Contact not found\n");  // Contact not found
    }

    return 0;
}
