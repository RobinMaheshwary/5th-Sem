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

void find_third_element_from_last()
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
    while (i < count - 2)
    {
        temp = temp->next;
        i++;
    }
    printf("%d\n", temp->data);
}

int main() {
    printf("robin, 20051828\n");
    int choice;
    while (1)
    {
        printf("1. Insert node\n");
        printf("2. Print list\n");
        printf("3. Find third element\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            {
                int data;
                printf("Enter data: ");
                scanf("%d", &data);
                insert_node(data);
                break;
            }
        case 2:
            {
                print_list();
                break;
            }
        case 3:
            {
                find_third_element_from_last();
                break;
            }
        case 4:
            {
                return 0;
            }
        default:
            {
                printf("Invalid choice\n");
            }
        }
    }
    return 0;
}