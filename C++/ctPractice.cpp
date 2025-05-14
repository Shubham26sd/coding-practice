#include <iostream>
using namespace std;

class Complex
{
  int a;
  int b;

public:
  friend Complex sumComplex(Complex c1, Complex c2);
  void setNumber(int x, int y)
  {
    a = x;
    b = y;
  }
  void printNumber()
  {
    cout << "Your number is " << a << " + " << b << "i" << endl;
  }
};

Complex sumComplex(Complex o1, Complex o2)
{
  Complex o3;
  o3.setNumber((o1.a + o2.a), (o1.b + o2.b));
  return o3;
}

int main()
{
  Complex o1, o2, sum;
  o1.setNumber(4, 6);
  o2.setNumber(1, 4);
  o1.printNumber();
  o2.printNumber();

  sum = sumComplex(o1, o2);
  sum.printNumber();
  return 0;
}