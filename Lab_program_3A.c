/*
NAME :- AYUSH KUMAR
BRANCH :- ECE A
ROLL NUMBER :- 2023ECE099
EXAM ROLL NUMBER :- 23294917099
ENROLLMENT NUMBER :- 23DOECBTEC000099
*/
#include <stdio.h>

// Function to perform binary search iteratively in an array
int binary_search_iterative(int arr[], int size, int target) {
    int left = 0, right = size - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}

int main() {
    int arr[] = {1, 3, 5, 7, 9, 11, 13, 15};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 7;

    int result = binary_search_iterative(arr, size, target);

    if (result == -1) {
        printf("Element not found.\n");
    } else {
        printf("Element found at index %d.\n", result);
    }

    return 0;
}
