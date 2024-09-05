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
        if (head == NULL)
        {
            head = ptr;
            ptr->next = head;
        }
        else
        {
            temp = head;
            while (temp->next != head)
            {
                temp = temp->next;
            }
            ptr->next = head;
            temp->next = ptr;
            head = ptr;
        }
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
        if (head == NULL)
        {
            head = ptr;
            ptr->next = head;
        }
        else
        {
            temp = head;
            while (temp->next != head)
            {
                temp = temp->next;
            }
            temp->next = ptr;
            ptr->next = head;
        }
        printf("Node Inserted at Last\n");
    }
}

// Function to delete the first node
void begin_delete()
{
    struct node *ptr, *temp;
    if (head == NULL)
    {
        printf("List is Empty\n");
    }
    else if (head->next == head)
    {
        free(head);
        head = NULL;
        printf("Node Deleted from Beginning\n");
    }
    else
    {
        temp = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }
        ptr = head;
        temp->next = head->next;
        head = head->next;
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
    else if (head->next == head)
    {
        free(head);
        head = NULL;
        printf("Node Deleted from Last\n");
    }
    else
    {
        temp = head;
        while (temp->next->next != head)
        {
            temp = temp->next;
        }
        ptr = temp->next;
        temp->next = head;
        free(ptr);
        printf("Node Deleted from Last\n");
    }
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
        do
        {
            if (ptr->data == item)
            {
                printf("Item Found at Position %d\n", i + 1);
                flag = 0;
                break;
            }
            ptr = ptr->next;
            i++;
        } while (ptr != head);
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
        do
        {
            printf("%d ", ptr->data);
            ptr = ptr->next;
        } while (ptr != head);
        printf("\n");
    }
}

int main()
{
    int choice = 0;

    while (choice != 9)
    {
        printf("Choose One Option From The Following List...\n");
        printf("1. Insert At Beginning\n2. Insert At Last\n3. Delete From Beginning\n4. Delete From Last\n5. Search\n6. Show\n7. Exit\n");

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
            begin_delete();
            break;
        case 4:
            last_delete();
            break;
        case 5:
            search();
            break;
        case 6:
            display();
            break;
        case 7:
            exit(0);
            break;
        default:
            printf("Invalid Choice...\n");
        }
    }

    return 0;
}