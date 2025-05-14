#include <iostream>
using namespace std;
class Complex
{
    int x, y;

public:
    Complex()
    {
        x = 0;
        y = 0;
    }
    // Complex(int a)
    // {
    //     x = a;
    //     y = 0;
    // }
    // Complex(int a, int b)
    // {
    //     x = a;
    //     y = b;
    // }

     /*Constructor with default arguments*/
    Complex(int a, int b=3) 
    {
        x = a;
        y = b;
    }
    void printNumber()
    {
        cout << "The complex number is : " << x << " + " << y << "i" << endl;
    }
};
int main()
{
    Complex c1(1, 2), c2(2), c3;
    c1.printNumber();
    c2.printNumber();
    c3.printNumber();
    return 0;
}