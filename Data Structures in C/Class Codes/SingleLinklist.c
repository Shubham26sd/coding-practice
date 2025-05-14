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
void del_beg();
void del_last();
void del_after();
void del_dup();
void sort();
void search_Unsort();
// void search_Sort();
void reverse();

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

        case 5:
            del_beg();
            break;

        case 6:
            del_last();
            break;

        case 7:
            del_after();
            break;

        case 8:
            del_dup();
            break;

        case 9:
            sort();
            break;

        case 10:
            search_Unsort();
            break;

        case 11:
            // search_Sort();
            printf("Under construction ^_^ ");
            break;

        case 12:
            reverse();
            break;

        case 13:
            exit(0);

        default:
            printf("\nWrong Choice");
        }
    }
}

void traverse()
{
    struct node *ptr;
    if (start == NULL)
        printf("\n\nEmpty List");
    else
    {
        printf("\n\nLinklist--->");
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
        printf("\nOver Flow");
        exit(0);
    }
    printf("Enter info value : ");
    scanf("%d", &data);
    tmp->info = data;
    tmp->link = start;
    start = tmp;
}

void insert_last()
{
    int data;
    struct node *tmp, *ptr;
    tmp = (struct node *)malloc(sizeof(struct node));
    if (tmp == NULL)
    {
        printf("\nOverFlow");
        exit(0);
    }
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
            ptr = ptr->link;
        ptr->link = tmp;
    }
}

void insert_after()
{
    struct node *tmp, *ptr;
    int item, pos, i;
    tmp = (struct node *)malloc(sizeof(struct node));
    if (tmp == NULL)
    {
        printf("Overflow");
        return;
    }
    printf("\nEnter the position after which you want to enter : ");
    scanf("%d", &pos);
    printf("\nEnter item value : ");
    scanf("%d", &item);
    tmp->info = item;
    ptr = start;
    for (i = 1; i < pos; i++)
    {
        if (ptr == NULL)
        {
            printf("Enter correct loc : ");
            return;
        }
        ptr = ptr->link;
    }
    tmp->link = ptr->link;
    ptr->link = tmp;
}

void del_beg()
{
    struct node *tmp;
    if (start == NULL)
    {
        printf("Under flow");
        return;
    }
    tmp = start;
    start = start->link;
    free(tmp);
}

void del_last()
{
    struct node *tmp, *ptr, *save;
    if (start == NULL)
    {
        printf("Underflow");
        return;
    }
    if (start->link == NULL)
    {
        tmp = start;
        start = start->link; // or start=NULL
    }
    else
    {
        save = start;
        ptr = start->link;
        while (ptr->link != NULL)
        {
            save = ptr;
            ptr = ptr->link;
        }
        save->link = NULL;
        tmp = ptr;
    }
    free(tmp);
}

void del_after()
{
    struct node *tmp, *ptr, *save;
    int i, pos;
    if (start == NULL)
    {
        printf("Underflow");
        return;
    }
    printf("Enter location : ");
    scanf("%d", &pos);
    if (pos == 0)
    {
        tmp = start;
        start = start->link;
    }
    else
    {
        i = 1;
        save = start;
        ptr = start->link;
        while (i < pos)
        {
            save = ptr;
            ptr = ptr->link;
            i++;
            if (ptr == NULL)
            {
                printf("Position not exist");
                return;
            }
        }
        save->link = ptr->link;
        tmp = ptr;
        free(tmp);
    }
}

void del_dup()
{
    struct node *ptr, *ptr1, *prev, *tmp;
    int data;
    if (start == NULL)
    {
        printf("Underflow");
        return;
    }
    ptr = start;
    while (ptr != NULL)
    {
        data = ptr->info;
        prev = ptr;
        ptr1 = ptr->link;
        while (ptr1 != NULL)
        {
            if (data == ptr1->info)
            {
                tmp = ptr1;
                prev->link = ptr1->link;
                ptr1 = ptr1->link;
                free(tmp);
            }
            else
            {
                prev = ptr1;
                ptr1 = ptr1->link;
            }
        }
        ptr = ptr->link;
    }
}

void sort()
{
    struct node *ptr, *ptr1;
    int tmp;
    if (start == NULL)
    {
        printf("List is empty");
        return;
    }
    for (ptr = start; ptr->link != NULL; ptr = ptr->link)
    {
        for (ptr1 = ptr->link; ptr1 != NULL; ptr1 = ptr1->link)
        {
            if (ptr->info > ptr1->info)
            {
                tmp = ptr->info;
                ptr->info = ptr1->info;
                ptr1->info = tmp;
            }
        }
    }
}

void search_Unsort()
{
    struct node *ptr;
    int item, pos;
    printf("Enter item value : ");
    scanf("%d", &item);
    ptr = start;

    while (ptr != NULL)
    {
        if (ptr->info == item)
        {
            break;
        }
        else
        {
            ptr = ptr->link;
            pos++;
        }
    }
    if (ptr == NULL)
        printf("Item not found");
    else
        printf("Item found at %d location", pos);
}

void reverse()
{
    struct node *p1, *p2, *p3;
    if (start == NULL)
    {
        printf("List is empty");
        return;
    }
    p1 = start;
    p2 = p1->link;
    p3 = p2->link;
    p1->link = NULL;
    p2->link = p1;
    while (p3 != NULL)
    {
        p1 = p2;
        p2 = p3;
        p3 = p3->link;
        p2->link = p1;
    }
    start = p2;
}