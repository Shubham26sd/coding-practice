#include <stdio.h>
#include <conio.h>

int linearSearch(int arr[], int size, int element)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == element)
            return i;
    }
    return -1;
}

int binarySearch(int arr[], int size, int element)
{
    int low, mid, high;
    low = 0;
    high = size - 1;
    
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (arr[mid] == element)
            return mid;

        if (arr[mid] < element)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return -1;
}

int main()
{
    // Unsorted array for linear search
    //  int arr[] = {1,3,5,56,4,3,23,5,4,54634,56,34};

    // Sorted array for binary search
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    int size = sizeof(arr) / sizeof(int);
    int element = 9;
    // int searchIndex = linearSearch(arr, size, element);
    int searchIndex = binarySearch(arr, size, element);
    printf("The element %d is found at index %d", element, searchIndex);
    return 0;
}