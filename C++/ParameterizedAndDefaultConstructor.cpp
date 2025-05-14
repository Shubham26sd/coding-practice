#include <iostream>
using namespace std;
class Complex
{
    int a, b;

public:
    void printNumber()
    {
        cout << "The complex number is : " << a << " + " << b << "i" << endl;
    }
    Complex(int, int);
};

// Complex ::Complex(int x, int y) /*--> Default constructor as it takes no value */
// {
//     a = x;
//     b = y;
//     // cout << "DONE" << endl;
// }

Complex ::Complex(int x, int y) /*Parameterized constructor as it takes 2 parameters **/
{
    a = x;
    b = y;
    // cout << "DONE" << endl;
}

int main()
{
    // Implicit call
    Complex a(4, 6);
    a.printNumber();

    // Explicit call
    Complex b = Complex(5, 7);

    b.printNumber();
    return 0;
}