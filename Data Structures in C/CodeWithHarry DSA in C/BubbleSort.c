#include <stdio.h>
void printArray(int *A, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}

void bubbleSort(int *A, int n)
{
    int tmp;
    int sorted = 1;
    for (int i = 0; i < n - 1; i++) // For passes
    {

        for (int j = 0; j < n - 1 - i; j++) // For comparison in each pass
        {
            if (A[j] > A[j + 1])
            {
                tmp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = tmp;
                sorted = 0;
            }
        }
        if (sorted)
        {
            printf("Already sorted\n");
            return;
        }
    }
}

int main()
{
    int A[] = {12, 54, 65, 7, 23, 9};
    // int A[] = {1, 2, 3, 4, 5, 6};
    int n = sizeof(A)/sizeof(int);
    printArray(A, n);
    bubbleSort(A, n);
    printArray(A, n);
    return 0;
}