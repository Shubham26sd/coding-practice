#include <stdio.h>
#define MAX 25
void main()
{
    int a[MAX], i, n;
    printf("Enter the limit of array : ");
    scanf("%d", &n);
    printf("Enter the array elements : \n");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    printf("Array Elements are : ");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);
}