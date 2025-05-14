#include <iostream>
using namespace std;

// pass by value
void update1(int n) // n here is a copy
{
    n++;
}

// pass by reference
void update2(int &n) // reference variable
{
    n++;
}

int &func(int a) // bad practice
{
    int num = a;
    int &ans = num; //**
    return ans;
}

int *fun(int n)
{
    int *ptr = &n;
    return ptr;
}

int main()
{
    // int i = 5;
    // int &j = i;
    // cout << i << endl;
    // i++;
    // cout << i << endl;
    // j++;
    // cout << i << endl;
    int n = 5;
    cout << "Before " << n << endl;
    // update1(n);
    update2(n);
    cout << "After " << n << endl;

    // func(n);

    fun(n);
    return 0;
}