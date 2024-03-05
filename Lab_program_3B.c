/*
NAME :- AYUSH KUMAR
BRANCH :- ECE A
ROLL NUMBER :- 2023ECE099
EXAM ROLL NUMBER :- 23294917099
ENROLLMENT NUMBER :- 23DOECBTEC000099
*/
#include <stdio.h>

// Function to perform binary search recursively in an array
int binary_search_recursive(int arr[], int left, int right, int target) {
    if (left > right) {
        return -1;
    }

    int mid = left + (right - left) / 2;
    if (arr[mid] == target) {
        return mid;
    } else if (arr[mid] < target) {
        return binary_search_recursive(arr, mid + 1, right, target);
    } else {
        return binary_search_recursive(arr, left, mid - 1, target);
    }
}

int main() {
    int arr[] = {1, 3, 5, 7, 9, 11, 13, 15};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 7;

    int result = binary_search_recursive(arr, 0, size - 1, target);

    if (result == -1) {
        printf("Element not found.\n");
    } else {
        printf("Element found at index %d.\n", result);
    }

    return 0;
}
