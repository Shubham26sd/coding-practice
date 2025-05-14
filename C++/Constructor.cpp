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
    Complex(void);
};

Complex ::Complex(void)
{
    a = 10;
    b = 30;
    cout<<"DONE"<<endl;
}
int main()
{
    Complex a;
    a.printNumber();
    return 0;
}