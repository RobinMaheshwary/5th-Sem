// Given a linked list and a value x, partition it such that all nodes less than x come before nodes
// greater than or equal to x.

#include <stdio.h>
#include <stdlib.h>

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

void partition_list(int x)
{
    struct node *less_than_x = NULL;
    struct node *greater_than_x = NULL;
    struct node *temp = head;
    while (temp != NULL)
    {
        if (temp->data < x)
        {
            struct node *new_node = (struct node *)malloc(sizeof(struct node));
            new_node->data = temp->data;
            new_node->next = NULL;
            if (less_than_x == NULL)
            {
                less_than_x = new_node;
            }
            else
            {
                struct node *temp1 = less_than_x;
                while (temp1->next != NULL)
                {
                    temp1 = temp1->next;
                }
                temp1->next = new_node;
            }
        }
        else
        {
            struct node *new_node = (struct node *)malloc(sizeof(struct node));
            new_node->data = temp->data;
            new_node->next = NULL;
            if (greater_than_x == NULL)
            {
                greater_than_x = new_node;
            }
            else
            {
                struct node *temp1 = greater_than_x;
                while (temp1->next != NULL)
                {
                    temp1 = temp1->next;
                }
                temp1->next = new_node;
            }
        }
        temp = temp->next;
    }
    struct node *temp1 = less_than_x;
    while (temp1->next != NULL)
    {
        temp1 = temp1->next;
    }
    temp1->next = greater_than_x;
    head = less_than_x;
}

int main()
{
    printf("robin, 20051828\n");
    int size;
    printf("Enter the size of the linked list: ");
    scanf("%d", &size);
    for (int i = 0; i < size; i++)
    {
        int data;
        printf("Enter the data: ");
        scanf("%d", &data);
        insert_node(data);
    }
    print_list();
    int x;
    printf("Enter the value of x: ");
    scanf("%d", &x);
    partition_list(x);
    print_list();
    return 0;
}