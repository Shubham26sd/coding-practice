#include<iostream>
using namespace std;

void swap(int *a, int *b){
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}
void swap1(int &a, int &b){
    int temp;
    temp=a;
    a=b;
    b=temp;
}
int main()
{
    int x=10, y=5;
    cout<<"x is : "<<x<<" y is : "<<y<<endl;
    // swap(&x,&y);
    swap1(x,y);
    cout<<"x is : "<<x<<" y is : "<<y<<endl;
    return 0;
}