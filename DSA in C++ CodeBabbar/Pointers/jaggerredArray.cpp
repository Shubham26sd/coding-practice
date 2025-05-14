#include <iostream>
using namespace std;

int main()
{
    int row;
    cout << "Enter no of rows -> ";
    cin >> row;

    // creating a 2d array
    int **arr = new int *[row];
    int *sizes = new int[row]; // to store the size of each row

    for (int i = 0; i < row; i++)
    {
        cout << "Enter size for row " << i + 1 << " -> ";
        cin >> sizes[i];
        arr[i] = new int[sizes[i]];
    }

    // taking input
    for (int i = 0; i < row; i++)
    {
        cout << "Enter " << sizes[i] << " elements for row " << i + 1 << " -> ";
        for (int j = 0; j < sizes[i]; j++)
        {
            cin >> arr[i][j];
        }
    }

    // showing output
    cout << endl;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < sizes[i]; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    // releasing memory
    for (int i = 0; i < row; i++)
    {
        delete[] arr[i];
    }
    delete[] arr;
    delete[] sizes;

    return 0;
}
