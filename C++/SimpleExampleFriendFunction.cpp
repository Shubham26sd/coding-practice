#include <iostream>
using namespace std;
class Y;

class X
{
    int data;
    friend void add(X, Y);

public:
    void setData(int a)
    {
        data = a;
    }
};

class Y
{
    int num;
    friend void add(X, Y);

public:
    void setNum(int a)
    {
        num = a;
    }
};

void add(X o1, Y o2)
{
    cout << "Sum of a and b is --> " << o1.data + o2.num;
}

int main()
{
    X a;
    a.setData(3);

    Y b;
    b.setNum(2);

    add(a, b);
    return 0;
}