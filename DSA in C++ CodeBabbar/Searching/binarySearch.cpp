#include <iostream>
using namespace std;

int binarySearch(int arr[], int size, int key)
{

    int start = 0;
    int end = size - 1;

    int mid = start + (end - start) / 2;

    while (start <= end)
    {
        if (key == arr[mid])
            return mid;

        // go to right wala part
        if (key > arr[mid])
            start = mid + 1;

        // go to left wala part
        else
            end = mid - 1;

        mid = start + (end - start) / 2; //to avoid integer overflow (start+end)/2 is replaced by this formula here
    
    }
    return -1;
}

int main()
{
    int even[6] = {2, 4, 6, 8, 12, 18};
    int odd[5] = {3, 8, 11, 14, 16};

    int evenIndex = binarySearch(even, 6, 6);
    int oddIndex = binarySearch(odd, 5, 14);

    cout << "Even Index of 6 is " << evenIndex << endl;
    cout << "Odd Index of 16 is " << oddIndex << endl;
}