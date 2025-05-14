#include <iostream>
using namespace std;

void update(int **p2)
{
    // p2 = p2 + 1;  /*--NO CHANGE*/

    // *p2 = *p2 + 1; /*-- CHANGE HOGA*/

    // **p2 = **p2 + 1; /*-- CHANGE HOGA*/
}

int main()
{

    // int i = 5;
    // int *p = &i;
    // int **p2 = &p;

    // cout << "printing p " << p << endl;
    // // cout << "address of p " << &p << endl;

    // cout << *p2 << endl;
    // cout << i << " " << *p << " " << **p2 << endl;
    // cout << &i << " " << p << " " << *p2 << endl;

    // cout << " before " << i << endl;
    // cout << " before " << p << endl;
    // cout << " before " << p2 << endl;
    // update(p2);
    // cout << endl;
    // cout << " after " << i << endl;
    // cout << " after " << p << endl;
    // cout << " after " << p2 << endl;

    return 0;
}