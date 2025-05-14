#include <stdio.h>
#include <conio.h>
#define MAX 25

void main()
{
    int a[MAX], i, n, item, flag = 0;
    printf("enter the limit of array-->");
    scanf("%d", &n);
    printf("enter the array element\n");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    printf("enter the item to be searched-->");
    scanf("%d", &item);
    for ( i = 0; i < n; i++)
    {
        if(a[i]==item)
        {
            flag=1;
            break;
        }
    }
    if(flag==1)
    printf("Item found at position %d",i+1);
    if(flag==0)
    printf("Item not found");
}