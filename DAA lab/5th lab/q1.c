#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

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

void find_middle_element()
{
    struct node *temp = head;
    int count = 0;
    while (temp != NULL)
    {
        temp = temp->next;
        count++;
    }
    temp = head;
    int i = 0;
    while (i < count / 2)
    {
        temp = temp->next;
        i++;
    }
    printf("%d\n", temp->data);
}

int main()
{
    printf("robin, 20051828\n");
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int data;
        scanf("%d",&data);
        insert_node(data);
    }
    print_list();
    find_middle_element();
    return 0;
}