#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the circular doubly linked list
struct node
{
    int data;
    struct node *next;
    struct node *prev;
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
        if (head == NULL)
        {
            ptr->next = ptr;
            ptr->prev = ptr;
            head = ptr;
        }
        else
        {
            struct node *last = head->prev;
            ptr->next = head;
            ptr->prev = last;
            last->next = ptr;
            head->prev = ptr;
            head = ptr;
        }
        printf("Node Inserted at Beginning\n");
    }
}

// Function to insert at the end of the list
void lastinsert()
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
        if (head == NULL)
        {
            ptr->next = ptr;
            ptr->prev = ptr;
            head = ptr;
        }
        else
        {
            struct node *last = head->prev;
            last->next = ptr;
            ptr->prev = last;
            ptr->next = head;
            head->prev = ptr;
        }
        printf("Node Inserted at Last\n");
    }
}

// Function to delete the first node
void begin_delete()
{
    if (head == NULL)
    {
        printf("List is Empty\n");
        return;
    }
    struct node *ptr = head;
    if (head->next == head)
    {
        head = NULL;
        free(ptr);
        printf("Node Deleted from Beginning\n");
        return;
    }
    struct node *last = head->prev;
    head = head->next;
    head->prev = last;
    last->next = head;
    free(ptr);
    printf("Node Deleted from Beginning\n");
}

// Function to delete the last node
void last_delete()
{
    if (head == NULL)
    {
        printf("List is Empty\n");
        return;
    }
    struct node *ptr = head;
    if (head->next == head)
    {
        head = NULL;
        free(ptr);
        printf("Node Deleted from Last\n");
        return;
    }
    struct node *last = head->prev;
    last->prev->next = head;
    head->prev = last->prev;
    free(last);
    printf("Node Deleted from Last\n");
}

// Function to search for an element in the list
void search()
{
    if (head == NULL)
    {
        printf("List is Empty\n");
        return;
    }
    struct node *ptr = head;
    int item, i = 1, flag = 0;
    printf("Enter Value to Search: ");
    scanf("%d", &item);
    do
    {
        if (ptr->data == item)
        {
            printf("Item Found at Position %d\n", i);
            flag = 1;
            break;
        }
        ptr = ptr->next;
        i++;
    } while (ptr != head);

    if (!flag)
    {
        printf("Item Not Found\n");
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
        } while (ptr != head); // Stop when we loop back to the head
        printf("\n");
    }
}

// Main function
int main()
{
    int choice = 0;

    while (choice != 7) // Update the condition to exit when choice is 7
    {
        printf("\nChoose One Option From The Following List...\n");
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