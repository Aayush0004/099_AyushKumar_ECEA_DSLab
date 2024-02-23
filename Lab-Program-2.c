/*
NAME :- AYUSH KUMAR
BRANCH :- ECE A
ROLL NUMBER :- 2023ECE099
EXAM ROLL NUMBER :- 23294917099
ENROLLMENT NUMBER :- 23DOECBTEC000099
*/
#include <stdio.h>
#include <stdlib.h>

// Function to create a dynamic array
int* createArray(int capacity)
{
    return (int*) malloc(capacity * sizeof(int));
}

// Function to perform linear search
int linearSearch(int arr[], int size, int key)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == key)
        {
            return i;
        }
    }
    return -1;
}

// Function to insert an element at a specified position
void insertElement(int arr[], int *size, int capacity, int pos, int value)
{
    if (*size >= capacity)
    {
        printf("Array is full. Cannot insert element.\n");
        return;
    }
    if (pos < 0 || pos > *size)
    {
        printf("Invalid position. Cannot insert element.\n");
        return;
    }
    for (int i = *size; i > pos; i--)
    {
        arr[i] = arr[i - 1];
    }
    arr[pos] = value;
    (*size)++;
}

// Function to delete an element from a specified position
void deleteElement(int arr[], int *size, int pos)
{
    if (pos < 0 || pos >= *size)
    {
        printf("Invalid position. Cannot delete element.\n");
        return;
    }
    for (int i = pos; i < *size - 1; i++)
    {
        arr[i] = arr[i + 1];
    }
    (*size)--;
}

// Function to reverse the array
void reverseArray(int arr[], int size)
{
    for (int i = 0; i < size / 2; i++)
    {
        int temp = arr[i];
        arr[i] = arr[size - i - 1];
        arr[size - i - 1] = temp;
    }
}

// Function to update the array
void updateArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        if (i % 2 == 0)
        {
            arr[i] = arr[i] * 2;
        }
        else
        {
            arr[i] = arr[i] + 5;
        }
    }
}

int main()
{
    int *arr, size, capacity, choice, pos, value, key;
    printf("Enter the capacity of the array: ");
    scanf("%d", &capacity);
    arr = createArray(capacity);
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    printf("Enter the elements of the array: ");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }
    while (1)
    {
        printf("\n1. Linear search for an element.\n2. Inserting an element at a specified position.\n3. Deleting an element from a specified position.\n4. Reversing the array.\n5. Updating the array.\n6. Exit.\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
                printf("Enter the element to search: ");
                scanf("%d", &key);
                int index = linearSearch(arr, size, key);
                if (index == -1)
                {
                    printf("Element not found.\n");
                }
                else
                {
                    printf("Element found at position %d.\n", index + 1);
                }
                break;
            case 2:
                printf("Enter the position and value to insert: ");
                scanf("%d%d", &pos, &value);
                insertElement(arr, &size, capacity, pos, value);
                break;
            case 3:
                printf("Enter the position to delete: ");
                scanf("%d", &pos);
                deleteElement(arr, &size, pos);
                break;
            case 4:
                reverseArray(arr, size);
                printf("Array reversed.\n");
                break;
        }
    }
}
