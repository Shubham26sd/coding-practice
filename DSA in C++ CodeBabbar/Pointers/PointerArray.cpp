#include <iostream>
using namespace std;

int main()
{
    /*
    int arr[10] = {2, 5, 6};
    cout << "address of first memory block " << arr << endl;
    cout << "address of first memory block " << &arr << endl;
    cout << "address of first memory block " << &arr[0] << endl;
    cout << &arr[1] << endl;

    cout << "Value at 0th memory block " << *arr << endl;
    cout << "Value at 0th memory block add 1 " << *arr + 1 << endl;
    cout << "Value at 1st memory block " << *(arr + 1) << endl;
    cout << "Value at 0th memory block + 1 => " << (*arr) + 1 << endl;

    cout<<1[arr]<<endl; //i[arr] is also valid O_O i[arr] = *(i+arr)

    int* p = &arr[0];
    // cout<<*p<<endl;
    cout<<endl;
    cout<<*arr<<endl;
    cout<<sizeof(*arr)<<endl;
    cout<<sizeof(arr)<<endl;
    cout<<sizeof(p)<<endl;
    cout<<sizeof(*p)<<endl;
    cout<<sizeof(&p)<<endl;
    */

    /*
        int a[20] = { 1, 2, 3, 5};
        cout << &a[0] << endl;
        cout << &a << endl;
        cout << a << endl;
        cout<<endl;

        int *p = &a[0];
        cout<<p<<endl;
        cout<<*p<<endl;
        cout<<&p<<endl;
     */
    int arr[10];
    // ERROR
    // arr = arr + 1;

    int *ptr = &arr[0];
    cout << ptr << endl;
    ptr = ptr + 1; // Ek block aage badh jao
    cout << ptr << endl;

    return 0;
}