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
    for ( i = 0; i < n-1; i++)
    {
        for ( j = i+1; j < n; j++)
        {
            if(a[i]>a[j])
            {
                temp = a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }
        
    }
    
    printf("\n");

    for (i = 0; i < n; i++)
        printf("%d ", a[i]);

    return 0;
}