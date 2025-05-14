#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *link;
} *start = NULL;

void traverseLinkedList(struct node *ptr)
{
    if (start == NULL)
        printf("List is empty");
        
    while (ptr != NULL)
    {
        printf("Element : %d\n", ptr->info);
        ptr = ptr->link;
    }
}

int main()
{
    struct node *tmp, *ptr;
    int data;
    char ch = 'y';
    while (ch == 'y' || ch == 'Y')
    {
        tmp = (struct node *)malloc(sizeof(struct node));
        if (tmp == NULL)
        {
            printf("Memory Overload");
            exit(0);
        }
        else
        {
            printf("Enter info value : ");
            scanf("%d", &data);
            tmp->info = data;
            tmp->link = NULL;
            if (start == NULL)
            {
                start = tmp;
            }
            else
            {
                ptr = start;
                while (ptr->link != NULL)    
                //For upto last second node
                    ptr = ptr->link;
                ptr->link = tmp; //For the last node
            }
        }
        printf("Do you want to add more nodes? : ");
        fflush(stdin);
        scanf(" %c", &ch);
    }
    traverseLinkedList(start);
    return 0;
}
