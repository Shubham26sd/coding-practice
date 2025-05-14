#include <iostream>
using namespace std;

int print(int *p)
{
    cout << *p << endl;
}

void update(int *p)
{
    // p = p + 1;
    // cout << "Update " << p << endl;
    *p = *p + 1;
}

int getSum(int *arr, int n) //*arr and arr[] same thing
{
    cout << "Size : " << sizeof(arr) << endl; // arr yaha pointer pass hora hai array nahii! Size: 4

    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    return sum;
}

int main()
{
    // int value = 5;
    // int *p = &value;

    // // print(p);
    // cout << " Before " << *p << endl;
    // update(p);
    // cout << " After " << *p << endl;
    // // print(p);

    int arr[6] = {1, 2, 3, 4, 5, 6};
    cout << "Sum is " << getSum(arr + 3, 3) << endl;

    return 0;
}