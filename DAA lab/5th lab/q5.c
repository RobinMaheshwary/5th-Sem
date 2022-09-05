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
    struct node *temp = head;
    struct node *prev = NULL;
    struct node *next = NULL;
    while (temp != NULL)
    {
        next = temp->next;
        if (temp->data < x)
        {
            if (prev == NULL)
            {
                head = next;
            }
            else
            {
                prev->next = next;
            }
            temp->next = head;
            head = temp;
        }
        else
        {
            prev = temp;
        }
        temp = next;
    }
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