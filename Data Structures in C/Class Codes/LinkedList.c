#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *link;
} *start = NULL;

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
            printf("Memory overload");
            exit(0);
        }
        else
        {
            printf("Enter info value : ");
            scanf("%d", &data);
            tmp->info = data;
            tmp->link = NULL;
            if (start == NULL)
                start = tmp;
            else
            {
                ptr = start;
                while (ptr->link != NULL)
                    ptr= ptr->link;
                ptr->link = tmp;
            }
            printf("Do you want to add more nodes\n");
            scanf(" %c", &ch);
        }
    }

    printf("Linked list -> ");
    if (start == NULL)
        printf("List is empty");
    else
    {
        ptr = start;
        while (ptr != NULL)
        {
            printf("%d", ptr->info);
            ptr = ptr->link;
        }
    }
    return 0;
}