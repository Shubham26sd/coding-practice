#include <stdio.h>
#include <stdlib.h>
struct node
{
    int info;
    struct node *link;
} *start = NULL;

void traverse();
void insert_beg();
void insert_last();
void insert_after();
// void del_beg();
// void del_last();
// void del_after();
// void del_dup();
// void sort();
// void search_Unsort();
// // void search_Sort();
// void reverse();
int main()
{
    int choice;
    while (1)
    {
        printf("\n\n---Menu---");
        printf("\n1.Traverse");
        printf("\n2.Insert at Beg");
        printf("\n3.Insert at Last");
        printf("\n4.Insert After");
        printf("\n5.Delete Beg");
        printf("\n6.Delete Last");
        printf("\n7.Delete After");
        printf("\n8.Delete Duplicate");
        printf("\n9.Sort");
        printf("\n10.Search Unsort");
        printf("\n11.Search Sort");
        printf("\n12.Reverse");
        printf("\n13.Exit");
        printf("\nEnter your choice : ");
        scanf("%d", &choice);
        printf("\n\n");

        switch (choice)
        {
        case 1:
            traverse();
            break;

        case 2:
            insert_beg();
            break;

        case 3:
            insert_last();
            break;

            case 4:
                insert_after();
                break;

            // case 5:
            //     del_beg();
            //     break;

            // case 6:
            //     del_last();
            //     break;

            // case 7:
            //     del_after();
            //     break;

            // case 8:
            //     del_dup();
            //     break;

            // case 9:
            //     sort();
            //     break;

            // case 10:
            //     search_Unsort();
            //     break;

            // case 11:
            //     // search_Sort();
            //     printf("Under construction ^_^ ");
            //     break;

            // case 12:
            //     reverse();
            //     break;

        case 13:
            exit(0);

        default:
            printf("\nWrong Choice");
        }
    }
    return 0;
}

void traverse()
{
    struct node *ptr;
    if (start == NULL)
        printf("Empty list");
    else
    {
        printf("Linked list --> ");
        ptr = start;
        while (ptr != NULL)
        {
            printf("%d ", ptr->info);
            ptr = ptr->link;
        }
    }
}

void insert_beg()
{
    int data;
    struct node *tmp;
    tmp = (struct node *)malloc(sizeof(struct node));
    if (tmp == NULL)
    {
        printf("Memory Overflow");
        exit(0);
    }
    else
    {
        printf("Enter info value : ");
        scanf("%d", &data);
        tmp->info = data;
        tmp->link = start;
        start = tmp;
    }
}

void insert_last()
{
    struct node *ptr, *tmp;
    int data;
    tmp = (struct node *)malloc(sizeof(struct node));
    if (tmp == NULL)
    {
        printf("Overflow");
        exit(0);
    }
    printf("Enter info value : ");
    scanf("%d", &data);
    tmp->info = data;
    tmp->link = NULL;
    if(start==NULL)
    {
        start=tmp;
    }
    else
    {
        ptr = start;
        while (ptr->link != NULL)
        {
            ptr = ptr->link;
        }
        ptr->link = tmp;
    }
}

void insert_after()
{
    
}