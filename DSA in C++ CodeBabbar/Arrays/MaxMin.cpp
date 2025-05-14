#include <iostream>
using namespace std;

int getMin(int arr[], int n)
{
    int min = INT8_MAX;
    for(int i=0; i<n; i++){
        if(arr[i] < min){
            min = arr[i];
        }
    }
    return min;
}
int getMax(int arr[], int n)
{
    int max = INT8_MIN;
    for(int i=0; i<n; i++){
        if(arr[i]>max){
            max = arr[i];
        }
    }
    return max;
}

int main()
{
    int size;
    cin >> size;

    int num[100];

    for (int i = 0; i < size; i++)
    {
        cin >> num[i];
    }

    cout<<"Maximum number is "<<getMax(num,size)<<endl;
    cout<<"Minimum number is "<<getMin(num,size);
    return 0;
}