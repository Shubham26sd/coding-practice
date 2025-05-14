#include <iostream>
using namespace std;

// My approach
// int partition(int *arr, int s, int e)
// {
//     int pivot = arr[e];
//     int i = s - 1;
//     for (int j = s; j < e ; j++)
//     {
//         if (arr[j] < pivot)
//         {
//             i++;
//             swap(arr[i], arr[j]);
//         }
//     }
//     swap(arr[i + 1], arr[e]);
//     return i + 1;
// }

// CodeHelp - Babbar Approach
int partition(int arr[], int s, int e)
{
    int pivot = arr[s];

    int cnt = 0;
    for (int i = s + 1; i <= e; i++)
    {
        if (arr[i] <= pivot)
            cnt++;
    }

    // place pivot at right position
    int pivotIndex = s + cnt;
    swap(arr[pivotIndex], arr[s]);

    // left and right wala part sambhal lete h
    int i = s, j = e;
    while (i <= j)
    {
        while (arr[i] < pivot)
        {
            i++;
        }
        while (arr[j] > pivot)
        {
            j--;
        }
        if (i < pivotIndex && j > pivotIndex)
        {
            swap(arr[i++], arr[j--]);
        }
        return pivotIndex;
    }
}

void quickSort(int arr[], int s, int e)
{
    if (s >= e)
        return;
    int q = partition(arr, s, e);
    quickSort(arr, s, q - 1);
    quickSort(arr, q + 1, e);
}

int main()
{
    int arr[5] = {5, 4, 3, 2, 1};
    int n = 5;
    quickSort(arr, 0, n - 1);
    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}