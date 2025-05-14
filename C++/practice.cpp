#include<iostream>
#include<string>
using namespace std;
struct person
{
    int age;
    string name;

};

int main()
{
    person p1;
    person *ptr = &p1;

    // p1.age = 10;
    // p1.name = "shubh";

    ptr->age=20;
    ptr->name="shubham";

    cout<<"name is "<<p1.name<<" and age is "<<p1.age<<endl;
    return 0;
}