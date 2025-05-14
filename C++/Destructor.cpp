#include <iostream>
using namespace std;

int count = 0;
class num
{
public:
    num()
    {
        cout << "This is the time when my constructor is called for the first time." << endl;
        count++;
    }
    ~num()
    {
        cout << "This is the time when my destructor is called for the first time." << endl;
        count--;
    }
};
int main()
{
    cout << "We are inside our main function." << endl;
    cout << "Creating first object n1" << endl;
    num n1;
    {
        cout << "Entering this block" << endl;
        cout << "Creating two more objects" << endl;
        num n2, n3;
        cout << "Exiting the block" << endl;
    }
    cout << "Back to main" << endl;
    return 0;
}