#include <iostream>
using namespace std;

int main()
{
    int n;
    cout<<"Enter then number : ";
    cin>>n;

    bool isPrime = 1;
    for(int i = 2; i<n; i++){
        if(n%i==0){
            isPrime=0;
            break;
        }
    }
    if (isPrime)
    {
        cout<<"Prime Number";
    }
    else
    {
        cout<<"Not a Prime Number";
    }
    
}