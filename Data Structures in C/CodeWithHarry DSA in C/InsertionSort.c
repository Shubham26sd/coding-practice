#include<stdio.h>

void insertionSort(int *A,int n)
{
    for (int i = 1; i <=n-1; i++)
    {
        int key,j;
        key = A[i];
        j = i-1;
        while(A[j]>key&&j>=0)
        {
            A[j+1]=A[j];
            j--;
        }
        A[j+1]=key;
    }
}
void printArray(int *A, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}
int main()
{
    int A[] = {5,4,3,2,1,0};
    int n = sizeof(A)/sizeof(int);
    printArray(A,n);
    insertionSort(A,n);
    printArray(A,n);
    return 0;
}