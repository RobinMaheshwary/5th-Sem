#include <stdio.h>


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

void remove_duplicates()
{
    struct node *temp = head;
    struct node *prev = NULL;
    struct node *current = NULL;
    while (temp != NULL)
    {
        prev = temp;
        current = temp->next;
        while (current != NULL)
        {
            if (current->data == temp->data)
            {
                prev->next = current->next;
                free(current);
                current = prev->next;
            }
            else
            {
                prev = current;
                current = current->next;
            }
        }
        temp = temp->next;
    }
}

int main()
{
    printf("robin, 20051828\n");
    int size;
    scanf("%d", &size);
    for (int i = 0; i < size; i++)
    {
        int data;
        scanf("%d", &data);
        insert_node(data);
    }
    remove_duplicates();
    print_list();
    return 0;
}