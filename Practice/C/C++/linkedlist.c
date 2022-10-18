#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* nxt;
};

void traverse(struct node* p){
    while(p!=NULL){
        printf("%d ",p->data);
        p = p->nxt;
    }
}

void insertAtBegining(struct node** head, struct node* new_node){
    new_node->nxt = *head;
    *head = new_node;
}

void insertAtEnd(struct node* new_node){
    struct node* p = *head;
    while(p->nxt!=NULL){
        p = p->nxt;
    }
    p->nxt = new_node;
    new_node->nxt = NULL;
}

void insertAtEnd(struct node* New_node){
    if()
}

int main(){

struct node* head;
struct node* node1;
struct node* node2;
struct node* new_node;


head = (struct node*)(malloc(sizeof(struct node)));
node1 = (struct node*)(malloc(sizeof(struct node)));
node2 = (struct node*)(malloc(sizeof(struct node)));
new_node = (struct node*)(malloc(sizeof(struct node)));


head->data = 1;
head->nxt = node1;

node1->data = 2;
node1->nxt = node2;

node2->data = 3;
node2->nxt = NULL;

new_node->data = 0;


insertAtBegining(&head,new_node);

traverse(head);
return 0;
}
