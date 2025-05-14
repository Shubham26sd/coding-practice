#include <iostream>
using namespace std;

void selectionSort(int *arr, int n)
{
    if (n == 0 || n == 1)
        return;
    int largest = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > arr[largest])
            largest = i;
    }
    swap(arr[n - 1], arr[largest]);
    
    selectionSort(arr, n - 1);
}

int main()
{
    int arr[5] = {2, 5, 1, 6, 9};
    selectionSort(arr, 5);
    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}