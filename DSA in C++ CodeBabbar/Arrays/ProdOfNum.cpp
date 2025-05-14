#include <iostream>
using namespace std;

int main()
{
    int n = 234;

    int product = 1;
    int sum = 0;
    for (int x = 10; n != 0; n = n / 10)
    {
        int r = n % x;
        product = product * r;
        sum = sum + r;
    }
    cout << product;
}