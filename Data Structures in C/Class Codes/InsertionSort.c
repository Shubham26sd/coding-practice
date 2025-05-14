#include <stdio.h>
#define MAX 25
int main()
{
    int a[MAX], i, n, temp, j;
    printf("Enter the limit of array : ");
    scanf("%d", &n);
    printf("Enter the array elements--> \n");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    for (i = 0; i < n; i++)
        printf("%d ", a[i]);

    // Insertion sort below
    for (i = 1; i < n; i++)
    {
        temp = a[i];
        j = i - 1;
        while (a[j] > temp && j >= 0)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = temp;
    }
    printf("\n");

    for (i = 0; i < n; i++)
        printf("%d ", a[i]);

    return 0;
}