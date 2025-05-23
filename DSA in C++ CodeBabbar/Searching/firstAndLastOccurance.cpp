#include <iostream>
using namespace std;

int firstOcc(int arr[], int n, int key)
{

    int s = 0, e = n - 1;
    int mid = s + (e - s) / 2;
    int ans = -1;

    while (s <= e)
    {
        if (key == arr[mid])
        {
            ans = mid;
            e = mid - 1;
        }

        else if (key > arr[mid])
        { // right me jao
            s = mid + 1;
        }
        else if (key < arr[mid])
        { // left me jao
            e = mid - 1;
        }
        mid = s + (e - s) / 2;
    }
    return ans;
}

int lastOcc(int arr[], int n, int key)
{
    int s = 0, e = n - 1;
    int mid = s + (e - s) / 2;
    int ans = -1;
    while(s<=e){
        if(arr[mid]==key){
            ans = mid;
            s = mid + 1;
        }

        else if(key > arr[mid]){ // right me jao
            s = mid + 1;
        }

        else if(key < arr[mid]){//left ,e jao
            e = mid - 1;
        }
        mid = s + (e-s)/2;
    }
    return ans;
}

int main()
{

    int even[6] = {1, 2, 3, 3, 3, 5};
    int answer1 = firstOcc(even, 6, 3);
    int answer2 = lastOcc(even, 6, 3);
    cout << "Leftmost position of 3 is at index " << answer1 << endl;
    cout << "Rightmost position of 3 is at index " << answer2 << endl;
    return 0;
}