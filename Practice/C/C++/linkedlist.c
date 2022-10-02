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

void insertAtBegining(struct node** head, n){
      
}

int main(){

struct node* head;
struct node* node1;
struct node* node2;
struct node* n;


head = (struct node*)(malloc(sizeof(struct node)));
node1 = (struct node*)(malloc(sizeof(struct node)));
node2 = (struct node*)(malloc(sizeof(struct node)));
n = (struct node*)(malloc(sizeof(struct node)));


head->data = 1;
head->nxt = node1;

node1->data = 2;
node1->nxt = node2;

node2->data = 3;
node2->nxt = NULL;

n->data = 0;


insertAtBegining(0,head);

traverse(head);
return 0;
}
