#include <iostream>
using namespace std;

class Base
{
    protected:
        int a = 10;

    private:
        int b = 20;

    public:
        int c = 30;
};

class Derived : protected Base
{
    public:
        void display()
        {
            cout << a;
        }
};

int main()
{
    Base b;
    Derived d;
    d.display();
    // cout<<d.a; // Will not work since a is protected in both base as well as derived class
    return 0;
}
