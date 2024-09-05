#include <stdio.h>
#include <stdlib.h> // Include this for exit() function

struct node
{
    int data;
    struct node *next;
};
struct node *head = NULL; // Initialize head to NULL

// Function to insert at the beginning
void beginsert()
{
    struct node *ptr;
    int item;
    ptr = (struct node *)malloc(sizeof(struct node));
    if (ptr == NULL)
    {
        printf("Memory Overflow\n");
        return;
    }
    else
    {
        printf("Enter Value to Insert: ");
        scanf("%d", &item);
        ptr->data = item;
        ptr->next = head;
        head = ptr;
        printf("Node Inserted at Beginning\n");
    }
}

// Function to insert at the end of the list
void lastinsert()
{
    struct node *ptr, *temp;
    int item;
    ptr = (struct node *)malloc(sizeof(struct node));
    if (ptr == NULL)
    {
        printf("Memory Overflow\n");
        return;
    }
    else
    {
        printf("Enter Value to Insert: ");
        scanf("%d", &item);
        ptr->data = item;
        ptr->next = NULL;
        if (head == NULL)
        {
            head = ptr;
            printf("Node Inserted at Last\n");
        }
        else
        {
            temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = ptr;
            printf("Node Inserted at Last\n");
        }
    }
}

// Function to insert at a specific position in the list
void random_insert()
{
    int item, loc, i;
    struct node *ptr, *temp;
    ptr = (struct node *)malloc(sizeof(struct node));
    if (ptr == NULL)
    {
        printf("Memory Overflow\n");
        return;
    }
    else
    {
        printf("Enter Value to Insert: ");
        scanf("%d", &item);
        ptr->data = item;
        printf("Enter the Position to Insert: ");
        scanf("%d", &loc);
        temp = head;
        for (i = 0; i < loc - 1; i++)
        {
            temp = temp->next;
            if (temp == NULL)
            {
                printf("Position Not Found\n");
                return;
            }
        }
        ptr->next = temp->next;
        temp->next = ptr;
        printf("Node Inserted at Position %d\n", loc);
    }
}

// Function to delete the first node
void begin_delete()
{
    struct node *ptr;
    if (head == NULL)
    {
        printf("List is Empty\n");
    }
    else
    {
        ptr = head;
        head = ptr->next;
        free(ptr);
        printf("Node Deleted from Beginning\n");
    }
}

// Function to delete the last node
void last_delete()
{
    struct node *ptr, *temp;
    if (head == NULL)
    {
        printf("List is Empty\n");
    }
    else if (head->next == NULL)
    {
        head = NULL;
        free(head);
        printf("Node Deleted from Last\n");
    }
    else
    {
        ptr = head;
        while (ptr->next != NULL)
        {
            temp = ptr;
            ptr = ptr->next;
        }
        temp->next = NULL;
        free(ptr);
        printf("Node Deleted from Last\n");
    }
}

// Function to delete a node at a specific position
void random_delete()
{
    struct node *ptr, *temp;
    int loc, i;
    printf("Enter the Position of Node to Delete: ");
    scanf("%d", &loc);
    ptr = head;
    for (i = 0; i < loc; i++)
    {
        temp = ptr;
        ptr = ptr->next;
        if (ptr == NULL)
        {
            printf("Position Not Found\n");
            return;
        }
    }
    temp->next = ptr->next;
    free(ptr);
    printf("Node Deleted from Position %d\n", loc);
}

// Function to search for an element in the list
void search()
{
    struct node *ptr;
    int item, i = 0, flag = 1;
    ptr = head;
    if (ptr == NULL)
    {
        printf("List is Empty\n");
        return;
    }
    else
    {
        printf("Enter Value to Search: ");
        scanf("%d", &item);
        while (ptr != NULL)
        {
            if (ptr->data == item)
            {
                printf("Item Found at Position %d\n", i + 1);
                flag = 0;
                break;
            }
            else
            {
                ptr = ptr->next;
                i++;
            }
        }
        if (flag)
        {
            printf("Item Not Found\n");
        }
    }
}

// Function to display the linked list
void display()
{
    struct node *ptr;
    ptr = head;
    if (ptr == NULL)
    {
        printf("List is Empty\n");
    }
    else
    {
        printf("The List Elements Are: ");
        while (ptr != NULL)
        {
            printf("%d ", ptr->data);
            ptr = ptr->next;
        }
        printf("\n");
    }
}

int main()
{
    int choice = 0;

    while (choice != 9)
    {
        printf("\n...Choose One Option From The Following List...\n");
        printf("1. Insert At Beginning\n2. Insert At Last\n3. Insert Item At Any Location\n4. Delete From Beginning\n5. Delete From Last\n6. Delete Item From Any Location\n7. Search\n8. Show\n9. Exit\n");

        printf("Enter Your Choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            beginsert();
            break;
        case 2:
            lastinsert();
            break;
        case 3:
            random_insert();
            break;
        case 4:
            begin_delete();
            break;
        case 5:
            last_delete();
            break;
        case 6:
            random_delete();
            break;
        case 7:
            search();
            break;
        case 8:
            display();
            break;
        case 9:
            exit(0);
            break;
        default:
            printf("Invalid Choice...\n");
        }
    }

    return 0;
}