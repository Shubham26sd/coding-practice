#include <iostream>
using namespace std;

bool isPresent(int arr[][4], int row, int col, int target)
{
    for (int row = 0; row < 3; row++)
    {

        for (int col = 0; col < 4; col++)
        {
            if (arr[row][col] == target)
                return 1;
        }
    }
    return 0;
}

void printSum(int arr[][4], int row , int col){
    for (int row = 0; row < 3; row++)
    {
        cout<<"Printing Sum => ";
        int sum = 0 ;
        for (int col = 0; col < 4; col++)
        {
            sum+= arr[row][col];
             
        }
        cout<<sum<<endl;
    }
    
}

int main()
{
    int arr[3][4];
    cout<<"Enter the elements"<<endl;

    for (int row = 0; row < 3; row++)
    {

        for (int col = 0; col < 4; col++)
        {
            cin >> arr[row][col];
        }
    }
    /* for (int col = 0; col < 4; col++)
    {

        for (int row = 0; row < 3; row++)
        {
            cout<< arr[row][col]<<" ";
        }
        cout<<endl;
    } */

    for (int row = 0; row < 3; row++)
    {

        for (int col = 0; col < 4; col++)
        {
            cout << arr[row][col] << " ";
        }
        cout << endl;
    }

    // int target;
    // cout << "Enter element to search " << endl;
    // cin >> target;

    // if (isPresent(arr, 3, 4, target))
    //     cout << "Element found";
    // else
    //     cout << "Element not found";
    printSum(arr,3,4);

    return 0;
}