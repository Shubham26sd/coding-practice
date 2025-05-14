#include <iostream>
using namespace std;

class complex
{
    int a;
    int b;
    friend complex sumComplex(complex o1, complex o2);

public:
    void setData(int v1, int v2)
    {
        a = v1;
        b = v2;
    }
    void printNumber()
    {
        cout << "The complex number is : " << a << " + " << b << "i" << endl;
    }
};

complex sumComplex(complex o1, complex o2) // Ye member function nahi bna hai Sirf ek bahari function hai, Isse sirf kuch permissions mili hai data access krne ki :)
{
    complex o3;
    o3.setData((o1.a + o2.a), (o1.b + o2.b));
    return o3;
}
int main()
{
    complex c1, c2, sum;
    c1.setData(1, 2);
    c1.printNumber();

    c2.setData(3, 4);
    c2.printNumber();

    sum = sumComplex(c1, c2);
    sum.printNumber();
    return 0;
}