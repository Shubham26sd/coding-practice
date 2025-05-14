#include <iostream>
using namespace std;

bool search(int arr[], int size, int key)
{
    for(int i=0; i<size; i++){
        if(arr[i]==key){
            return 1;
        }
    }
    return 0;
}

int main()
{
    int arr[10] = {1, 3, 52, 22, -19, 12, 48, 0, 90, 10};
    cout << "Enter the element to search for : ";
    int key;
    cin >> key;
    bool found = search(arr, 10, key);
    if (found)
    {
        cout << "Key is found" << endl;
    }
    else
    {
        cout << "Key not found" << endl;
    }
}