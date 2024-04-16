#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <stdbool.h>
struct node
{
    int data;
    struct node *next;
    struct node *previous;
};
struct node *head, *tail;
void createlist(int item)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ;

    if (ptr == NULL)
    {
        printf("\nOVERFLOW\n");
    }
    else
    {
        ptr->data = item;
        ptr->next = NULL;
        if (head == NULL)
        {
            ptr->previous = NULL;
            head = tail = ptr;
            printf("\nNODE INSERTED\n");
        }
        else
        {
            tail->next = ptr;
            ptr->previous = tail;
            tail = ptr;
            printf("\nNODE INSERTED\n");
        }
    }
}
void display()
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr = head;
    while (ptr != NULL)
    {
        printf("%d->", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL\n");
}
void displayreverse()
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr = tail;
    while (ptr != NULL)
    {
        printf("%d->", ptr->data);
        ptr = ptr->previous;
    }
    printf("NULL\n");
}
struct node *head, *tail;
void addbegin()
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    int item;
    if (ptr == NULL)
    {
        printf("\nOVERFLOW\n");
    }
    else
    {
        printf("Please enter the value you want to add\n");
        scanf("%d", &item);
        ptr->data = item;
        ptr->previous = NULL;
        if (head == NULL)
        {
            ptr->next = NULL;
            head = tail = ptr;
            printf("\nNODE INSERTED\n");
        }
        else
        {
            ptr->next = head;
            head->previous = ptr;
            head = ptr;
            printf("\nNODE INSERTED\n");
        }
    }
}
void addend()
{
    int item;
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    if (ptr == NULL)
    {
        printf("\nOVERFLOW\n");
    }
    else
    {
        printf("Please enter a value for the node \n");
        scanf("%d", &item);
        ptr->data = item;
        ptr->next = NULL;
        if (head == NULL)
        {
            ptr->previous = NULL;
            head = tail = ptr;
            printf("\nNODE INSERTED\n");
        }
        else
        {
            ptr->previous = tail;
            tail->next = ptr;
            tail = ptr;
            printf("\nNODE INSERTED\n");
        }
    }
}
void addrandom()
{
    int i, n, item;
    printf("Please enter the position you want to add node \n");
    scanf("%d", &n);
    struct node *ptr = (struct node *)malloc(sizeof(struct node *));
    ptr = head;
    struct node *ptr1 = (struct node *)malloc(sizeof(struct node));
    printf("Please enter the value of the node\n");
    scanf("%d", &item);
    ptr1->data = item;
    if (ptr == NULL)
    {
        printf("\nOVERFLOW\n");
    }
    else
    {
        for (i = 1; i < n; i++)
        {
            ptr = ptr->next;
            if (ptr->next == NULL)
            {
                printf("No node availabe\n");
            }
        }
        ptr->previous->next = ptr1;
        ptr1->previous = ptr->previous;

        ptr1->next = ptr;
        ptr->previous = ptr1;
        ptr = ptr1;
    }
}
void deletebeg()
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    struct node *ptr1 = (struct node *)malloc(sizeof(struct node));
    ptr = head;
    if (head == NULL)
    {
        printf("\nLIST IS EMPTY\n");
    }
    else
    {

        ptr1 = ptr->next;
        ptr1->previous = NULL;
        free(ptr);
        head = ptr1;

        printf("NODE DELETED\n");
    }
}
void deleteend()
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    struct node *ptr2 = (struct node *)malloc(sizeof(struct node));
    ptr = tail;
    if (tail == NULL)
    {
        printf("\nLIST IS EMPTY\n");
    }
    else
    {
        ptr2 = ptr->previous;
        ptr2->next = NULL;
        free(ptr);
        tail = ptr2;
    }
}
void deleterandom()
{
    int i, n;
    struct node *ptr, *ptr1;
    ptr = (struct node *)malloc(sizeof(struct node));
    ptr1 = (struct node *)malloc(sizeof(struct node));
    printf("Please enter the position you want to delete\n");
    scanf("%d", &n);
    ptr = head;
    if (head == NULL)
    {
        printf("\nLIST IS EMPTY\n");
    }
    else
    {
        for (i = 2; i < n; i++)
        {
            ptr = ptr->next;
            if (ptr->next == NULL)
            {
                printf("the given node is not available in the list\n");
            }
            else if (i > n)
            {
                printf("node not available\n");
            }
        }
        if (ptr->next->next == NULL)
        {
            deleteend();
        }
        else if (ptr->previous == NULL)
        {
            deletebeg();
        }

        else
        {
            ptr1 = ptr->next;
            ptr->next = ptr1->next;
            ptr1->next->previous = ptr;
            free(ptr1);
        }
    }
}
void search()
{
    int item, i = 0;
    bool found = false;
    struct node *ptr;
    ptr = (struct node *)malloc(sizeof(struct node));
    printf("Please enter the data you want to search in the list \n");
    scanf("%d", &item);
    ptr = head;
    while (ptr != NULL)
    {
        if (ptr->data == item)
        {
            printf("The given data is found at %d node\n", i+1);
            found = true;
        }

        i += 1;
        ptr = ptr->next;
    }
    if(found  == false) {
        printf("there is no %d in the list\n",item);
    }
}
int main()
{
    int i, n, choice, data;
    printf("Please type the number of nodes you want in your linked list\n");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("Please enter the value for %d node \n", i + 1);
        scanf("%d", &data);
        createlist(data);
    }
    printf("\nDisplaying the created list\n");
    display();
    while (choice != 10)
    {
        printf("--------------------------------------------MENU--------------------------------------------\n");
        printf("options availabe\n");
        printf("1.ADD node in the beginning\n");
        printf("2.ADD node in the end\n");
        printf("3.ADD node randomly in the list except first and last\n");
        printf("4.DELETE node from the beginning\n");
        printf("5.DELETE node in the end of the list\n");
        printf("6.DELETE node randomly from the list\n");
        printf("7.DISPLAY the list normally\n");
        printf("8.DISPLAY the list in reverse order\n");
        printf("9.SEARCH a value in the list\n");
        printf("10.exit code\n");
        printf("\n\nPlease enter your choice\n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            addbegin();
            break;
        case 2:
            addend();
            break;
        case 3:
            addrandom();
            break;
        case 4:
            deletebeg();
            break;
        case 5:
            deleteend();
            break;
        case 6:
            deleterandom();
        case 7:
            display();
            break;
        case 8:
            displayreverse();
            break;
        case 9:
            search();
            break;
        case 10:
            exit(0);
            break;
        default:
            printf("INVALID INPUT\n");
        }
        choice = 0;
    }
    getch();
    return 0;
}
