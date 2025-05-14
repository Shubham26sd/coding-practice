#include <iostream>
using namespace std;

void print(int n)
{
    // cout<<n<<endl;
    // base case
    if (n == 0)
    {
        return;
    }

    print(n - 1);
    cout << n << endl;
    // return n * count(n - 1);
}

int main()
{
    int n;
    cin >> n;
    print(n);
    return 0;
}