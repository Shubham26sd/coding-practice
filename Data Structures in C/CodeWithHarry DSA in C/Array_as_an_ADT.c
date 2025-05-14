#include <stdio.h>
#include <stdlib.h>

struct MyArray
{
    int total_size;
    int used_size;
    int *ptr;
};

void createArray(struct MyArray *a, int tSize, int uSize)
{
    // (*a).total_size = tSize;
    // (*a).used_size = uSize;
    // (*a).ptr = (int *)malloc(sizeof(tsize * (int)));

    a->total_size = tSize;
    a->used_size = uSize;
    a->ptr = (int *)malloc(tSize * sizeof(int));
}

void show(struct MyArray *a)
{
    for (int i = 0; i < a->used_size; i++)
    {
        printf("%d\n", (a->ptr)[i]);
    }
}

void set(struct MyArray *a)
{
    for (int i = 0; i < a->used_size; i++)
    {
        int n;
        printf("Enter element %d : ", i);
        scanf("%d", &n);
        (a->ptr)[i] = n;
    }
}

int main()
{
    struct MyArray marks;
    createArray(&marks, 10, 2);
    printf("We are running set now.\n");
    set(&marks);
    printf("We are running show now.\n");
    show(&marks);
    return 0;
}