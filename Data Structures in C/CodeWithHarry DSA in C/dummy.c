#include <stdio.h>
#include <stdlib.h>
int main()
{
    int a=10;
    int *ptr;
    ptr = &a;
    // *ptr = 20;
    printf("%d",*ptr);
    return 0;
}