#include <stdio.h>
#include <stdlib.h>
struct node
{
    int info;
    struct node *link;
} *start = NULL;

void traverseLinkedList(struct node *ptr)
{
    while (ptr != NULL)
    {
        printf("Element: %d\n", ptr->info);
        ptr = ptr->link;
    }
}
struct node *deleteFirst(struct node *head)
{
    struct node *ptr = head;
    head = head->link;
    free(ptr);
    return head;
}

struct node *deleteAtIndex(struct node *head, int index)
{
    struct node *p = head;
    struct node *q = head->link;
    for (int i = 0; i < index - 1; i++)
    {
        p = p->link;
        q = q->link;
    }
    p->link = q->link;
    free(q);
    return head;
}

int main()
{
    struct node *head, *second, *third;
    head = (struct node *)malloc(sizeof(struct node));
    second = (struct node *)malloc(sizeof(struct node));
    third = (struct node *)malloc(sizeof(struct node));

    head->info = 1;
    head->link = second;

    second->info = 2;
    second->link = third;

    third->info = 3;
    third->link = NULL;

    printf("List before deletion\n");
    traverseLinkedList(head);

    // head = deleteFirst(head);
    // head = deleteAtIndex(head, 2);
    head = deleteLast(head, 2);
    printf("List after deletion\n");
    traverseLinkedList(head);

    return 0;
}