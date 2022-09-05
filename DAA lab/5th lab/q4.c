// WAP in c to convert a sorted list to a binary search tree.

// Language: c
// Path: DAA lab/5th lab/q5.c


#include <stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;

void insertNode(int data){
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;
    if(head == NULL){
        head = new_node;
    }
    else{
        struct node* temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = new_node;
    }
}

void printList(){
    struct node* temp = head;
    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void partitionList(int x){
    struct node* temp = head;
    struct node* prev = NULL;
    struct node* next = NULL;
    while(temp != NULL){
        next = temp->next;
        if(temp->data < x){
            if(prev == NULL){
                head = next;
            }
            else{
                prev->next = next;
            }
            temp->next = NULL;
            insertNode(temp->data);
        }
        else{
            prev = temp;
        }
        temp = next;
    }
}

int main(){
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int data;
        scanf("%d", &data);
        insert_node(data);
    }
    printList();
    partitionList(3);
    printList();
    return 0;
}
