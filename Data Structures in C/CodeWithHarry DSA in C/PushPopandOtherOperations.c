#include <stdio.h>
#include <stdlib.h>
int isFull();
int isEmpty();
struct stack
{
    int size;
    int top;
    int *arr;
};

void push(struct stack *s, int a)
{
    if (isFull(s))
        printf("Stack Overflow");
    else
    {
        s->top++;
        s->arr[s->top] = a;
    }
}

int pop(struct stack *s)
{
    if (isEmpty(s))
    {
        printf("Stack is empty. Cannot pop from stack.");
        exit(0);
    }
    else
    {
        int val = s->arr[s->top];
        s->top--;
        return val;
    }
}
int isEmpty(struct stack *ptr)
{
    if (ptr->top == -1)
        return 1;
    else
        return 0;
}
int isFull(struct stack *ptr)
{
    if (ptr->top == ptr->size - 1)
        return 1;
    else
        return 0;
}

int peek(struct stack *s,int i)
{
    int arrInd = s->top-i+1;
    if(arrInd < 0)
    {
        printf("Not a valid position for the stack.\n");
        return -1;
    }
    else
    {
        return s->arr[arrInd];
    }    
}
int stackTop(struct stack *s)
{
    return s->arr[s->top];
}
int stackBottom(struct stack *s)
{
    return s->arr[0];
}
int main()
{
    struct stack *sp = (struct stack *)malloc(sizeof(struct stack));
    sp->size = 10;
    sp->top = -1;
    sp->arr = (int *)malloc(sp->size * sizeof(int));
    printf("Stack has been created successfully.\n");
    push(sp, 34);
    push(sp, 23);
    push(sp, 14);
    push(sp, 12);
    // printf("Popped element : %d\n", pop(sp));
    // printf("Popped element : %d\n", pop(sp));
    // printf("Popped element : %d\n", pop(sp));
    // printf("Popped element : %d\n", pop(sp));
    // printf("Popped element : %d\n", pop(sp));
    printf("Peeked element : %d\n",peek(sp,3));
    printf("Topmost element is %d\n",stackTop(sp));
    printf("Bottom most element is %d\n",stackBottom(sp));
    return 0;
}