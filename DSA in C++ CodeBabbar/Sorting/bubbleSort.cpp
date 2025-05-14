#include <bits/stdc++.h>
using namespace std;

void printArray(vector<int> arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

void bubbleSort(vector<int> &arr, int n) // Khudse kiya huu ^-^
{
     bool swapped = false;
    for (int i = 1; i < n ; i++)
    {
        for (int j = 0; j < n  - i; j++)
        {

            if (arr[j] > arr[j + 1]){

                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if(swapped == false){
            cout<<"already sorted";
            break;
        }
    }
}

int main()
{

    vector<int> arr{5, 1, 2, 3, 4, 6, 15, 0};
    bubbleSort(arr, arr.size());
    printArray(arr, arr.size());
}
