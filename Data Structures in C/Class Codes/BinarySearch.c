#include <stdio.h>
#include <conio.h>
#define MAX 25
void main()
{
    int a[MAX], i, n, item, low, mid, high;
    printf("enter the limit of array-->");
    scanf("%d", &n);
    printf("enter the array element in sorted order\n");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("enter the item to be searched-->");
    scanf("%d", &item);

    low = 0;
    high = n - 1;
    mid = (low + high) / 2;
    while (low <= high && a[mid] != item)
    {
        if (a[mid] > item)
        {
            high = mid - 1;
        }
        if (a[mid] < item)
        {
            low = mid + 1;
        }
        mid = (low + high) / 2;
    }
    if (a[mid] == item)
        printf("Item found at %d position", mid + 1);
    else
    {
        printf("Item not found");
    }
}