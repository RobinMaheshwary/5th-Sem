#include <stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;

void insert_node(int data)
{
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;
    if (head == NULL)
    {
        head = new_node;
    }
    else
    {
        struct node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = new_node;
    }
}

void print_list()
{
    struct node *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// check if a given linked list contains a cycle

int check_cycle(struct node *head)
{
    struct node *slow_ptr = head;
    struct node *fast_ptr = head;
    while (slow_ptr != NULL && fast_ptr != NULL && fast_ptr->next != NULL)
    {
        slow_ptr = slow_ptr->next;
        fast_ptr = fast_ptr->next->next;
        if (slow_ptr == fast_ptr)
        {
            return 1;
        }
        
    }
    return 0;
}

int main() {
    int choice;
    printf("1. Insert node\n2. Print list\n3. Check if list contains a cycle\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    int data;
    while (choice != 0)
    {
        switch (choice)
        {
        case 1:
            printf("Enter data: ");
            scanf("%d", &data);
            insert_node(data);
            break;
        case 2:
            print_list();
            break;
        case 3:
            if (check_cycle(head))
            {
                printf("List contains a cycle\n");
            }
            else
            {
                printf("List does not contain a cycle\n");
            }
            break;
        default:
            printf("Invalid choice\n");
            break;
        }
    }
    return 0;
}