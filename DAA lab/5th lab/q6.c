//  reverse a singly linked list without recursion/

#include<stdio.h>
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

void reverse_list()
{
    struct node *prev = NULL;
    struct node *current = head;
    struct node *next = NULL;
    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
}

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int data;
        scanf("%d", &data);
        insert_node(data);
    }
    print_list();
    reverse_list();
    print_list();
    return 0;
}


