#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int ans = 0;
    int i = 0;
    while (n != 0)
    {

        int digit = n % 10;

        if (digit == 1)
        {
            ans = (pow(2, i) * digit) + ans;
        }

        n = n / 10;
        i++;
    }

    cout<<"Answer is "<< ans << endl;
    
}
