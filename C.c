#include <stdio.h>

#define SIZE 100

void linearSearch(int arr[], int size, int target);
void insertElement(int arr[], int size, int position, int value);
void deleteElement(int arr[], int size, int position);
void reverseArray(int arr[], int size);
void updateArray(int arr[], int size);

int main() {
    int arr[SIZE];
    int size, position, value, target;

    printf("Enter the size of the array (max %d): ", SIZE);
    scanf("%d", &size);

    printf("Enter the elements of the array:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    int choice;
    while (1) {
        printf("\nChoose an operation:\n");
        printf("1. Linear search for an element.\n");
        printf("2. Insert an element at a specified position.\n");
        printf("3. Delete an element from a specified position.\n");
        printf("4. Reverse the array.\n");
        printf("5. Update the array.\n");
        printf("6. Quit.\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the target element: ");
                scanf("%d", &target);
                linearSearch(arr, size, target);
                break;
            case 2:
                printf("Enter the position and value: ");
                scanf("%d %d", &position, &value);
                insertElement(arr, size, position, value);
                size++;
                break;
            case 3:
                printf("Enter the position: ");
                scanf("%d", &position);
                deleteElement(arr, size, position);
                size--;
                break;
            case 4:
                reverseArray(arr, size);
                break;
            case 5:
                updateArray(arr, size);
                break;
            case 6:
                return 0;
            default:
                printf("Invalid choice.\n");
                break;
        }
    }

    return 0;
}

void linearSearch(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            printf("Element found at index %d.\n", i);
            return;
        }
    }
    printf("Element not found.\n");
}

void insertElement(int arr[], int size, int position, int value) {
    for (int i = size - 1; i >= position; i--) {
        arr[i + 1] = arr[i];
    }
    arr[position] = value;
}

void deleteElement(int arr[], int size, int position) {
    for (int i = position; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }
}

void reverseArray(int arr[], int size) {
    for (int i = 0; i < size / 2; i++) {
        int temp = arr[i];
        arr[i] = arr[size - i - 1];
        arr[size - i - 1] = temp;
    }
}

void updateArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        if (i % 2 == 0) {
            arr[i] = arr[i] * 2;
        } else {
            arr[i] = arr[i] + 5;
        }
    }
}
