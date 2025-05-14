#include <bits/stdc++.h>
using namespace std;

void printArray(vector<int> arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

void insertionSort(vector<int> &arr, int n)
{

    for (int i = 1; i < n; i++)
    {
        int temp = arr[i];
        int j = i - 1;
        while(j>=0)
        {

            if (temp < arr[j])
            {
                // shift
                arr[j + 1] = arr[j];
            }
            else
            { // rukjao
                break;
            }
            j--;
        }
        arr[j + 1] = temp;
    }
}

int main()
{

    vector<int> arr{5, 3, 2, 1, 4};
    insertionSort(arr, arr.size());
    printArray(arr, arr.size());
}