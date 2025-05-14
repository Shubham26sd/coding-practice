#include <stdio.h>
void display(int arr[], int size)
{
    // Code for Traversal
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
void indDeletiion(int arr[], int size, int index)
{
    for (int i = index; i < size-1; i++)
    {
        arr[i] = arr[i+1];
    }
}
int main()
{
    int arr[100] = {1, 2, 4, 6, 77};
    int size = 5, element = 45, index = 2;
    display(arr, size);
    indDeletiion(arr,size,index);
    size = size-1;
    display(arr, size);
    return 0;
}