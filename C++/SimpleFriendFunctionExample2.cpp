#include <iostream>
using namespace std;
class Y;

class X
{
    friend void exchange(X &, Y &);
    int val1;

public:
    void inData(int a)
    {
        val1 = a;
    }
    void display(void)
    {
        cout << val1 << endl;
    }
};

class Y
{
    int val2;
    friend void exchange(X &, Y &);

public:
    void inData(int a)
    {
        val2 = a;
    }
    void display(void)
    {
        cout << val2 << endl;
    }
};
void exchange(X &a, Y &b)
{
    int tmp;
    tmp = a.val1;
    a.val1 = b.val2;
    b.val2 = tmp;
}

int main()
{
    X c1;
    Y c2;
    c1.inData(12);
    c2.inData(50);
    exchange(c1, c2);
    cout << "The value of c1 after exchanging becomes : ";
    c1.display();
    cout << "The value of c2 after exchanging becomes : ";
    c2.display();

    return 0;
}