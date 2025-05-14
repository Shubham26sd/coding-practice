#include <stdio.h>
#include <stdlib.h>
struct Node *top = NULL;

struct Node
{
    int data;
    struct Node *next;
};

int isEmpty(struct Node *top)
{
    if (top == NULL)
        return 1;
    return 0;
}
int isFull(struct Node *top)
{
    struct Node *p = (struct Node *)malloc(sizeof(struct Node));
    if (p == NULL)
        return 1;
    return 0;
}
void traverseLinkedList(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}

struct Node *push(struct Node *top, int x)
{
    if (isFull(top))
    {
        printf("Stack Overflow\n");
    }
    else
    {
        struct Node *n = (struct Node *)malloc(sizeof(struct Node));
        n->data = x;
        n->next = top;
        top = n;
        return top;
    }
}
int pop(struct Node **top)
{
    if (isEmpty(*top))
    {
        printf("Stack Underflow\n");
    }
    else
    {
        struct Node *n = *top;
        *top = (*top)->next;
        int x = n->data;
        free(n);
        return x;
    }
}

int peek(int pos)
{
    struct Node *ptr = top;
    for (int i = 0; (i < pos - 1 && ptr != NULL); i++)
    {
        ptr = ptr->next;
    }
    if (ptr != NULL)
        return ptr->data;
    else
        return -1;
}

int main()
{

    top = push(top, 78);
    top = push(top, 7);
    top = push(top, 8);
    top = push(top, 23);
    traverseLinkedList(top);
    // int element = pop(&top);
    // printf("Popped element is %d\n",element);
    // traverseLinkedList(top);  //Dikkt aayi isliye top ko global varaible bana diye Ya fir other option hai &top use karo aur pop ke andar **top use krke
    for (int i = 1; i <= 4; i++)
    {
        printf("Peeked element at %d position : %d\n", i, peek(i));
    }

    return 0;
}