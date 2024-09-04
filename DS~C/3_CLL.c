#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* prev;
    struct node* next;
};

struct node* createnode(int data){
    struct node* newnode=malloc(sizeof(struct node));
    newnode->data=data;
    newnode->prev=newnode;
    newnode->next=newnode;
    return newnode;
}

struct node* insert_at_beg(struct node* tail, int data){
    struct node* newnode=createnode(data);
    struct node* temp=tail->next;
    newnode->next=temp;
    newnode->prev=tail;
    tail->next=newnode;
    temp->prev=newnode;
    return tail;
}

struct node* insert_at_end(struct node* tail, int data){
    struct node* newnode=createnode(data);
    if(tail==NULL){
        return newnode;
    }
    struct node* temp=tail->next;
    tail->next=newnode;
    newnode->prev=tail;
    newnode->next=temp;
    temp->prev=newnode;
    tail=newnode;
    return tail;
}

struct node* insert_at_pos(struct node* tail, int data, int pos){
    struct node* newnode=createnode(data);
    struct node* temp=tail->next;
    while(pos>2){
        temp=temp->next;
        pos--;
    }
    struct node* temp2=temp->next;
    newnode->prev=temp;
    newnode->next=temp2;
    temp->next=newnode;
    temp2->prev=newnode;
    return tail;
}

struct node* delete_at_front(struct node* tail){
    struct node* temp=tail->next;
    tail->next=temp->next;
    temp->next->prev=tail;
    free(temp);
    return tail;
}

struct node* delete_at_end(struct node* tail){
    struct node* temp=tail->next;
    struct node* temp2=tail->prev;
    temp2->next=temp;
    temp->prev=temp2;
    free(tail);
    tail=NULL;
    tail=temp2;
    return tail;
}

struct node* delete_at_pos(struct node* tail, int pos){
    struct node* temp=tail->next;
    while(pos>1){
        temp=temp->next;
        pos--;
    }
    struct node* temp2=temp->prev;
    temp2->next=temp->next;
    temp->next->prev=temp2;
    free(temp);
    return tail;
}

void display(struct node* tail){
    if(tail==NULL){
        printf("Empty");
    }
    struct node* temp=tail->next;
    do{
        printf("Element is: %d\n",temp->data);
        temp=temp->next;
    }while(temp!=tail->next);
    printf("\n");
}

int main() {
    struct node* tail=malloc(sizeof(struct node));
    tail=createnode(40);
    tail=insert_at_beg(tail,20);
    tail=insert_at_beg(tail,10);
    tail=insert_at_pos(tail,30,3);
    tail=insert_at_end(tail,50);
    tail=delete_at_front(tail);
    tail=delete_at_pos(tail,2);
    tail=delete_at_end(tail);
    display(tail);
    return 0;
}