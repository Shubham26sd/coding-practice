#include <stdio.h>
#include <conio.h>
#define MAX 25
void main()
{
    int a[MAX], i, n, pos, item;
    printf("Enter the limit of array-->");
    scanf("%d", &n);
    printf("Enter the array items-->");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    for (i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("Enter the item to be inserted-->");
    scanf("%d", &item);
    printf("Enter the position-->");
    scanf("%d", &pos);

    if (pos < 0 || pos > MAX)
    {
        printf("Enter valid position");
        return;
    }

    for (i = n - 1; i >= pos-1; i--)
    {
        a[i + 1] = a[i];
    }
    a[pos-1] = item;
    n += 1;

    printf("The new array after insertion is -->");
    for (i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
}