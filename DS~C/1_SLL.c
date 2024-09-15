#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* link;
};

struct node* createnode(struct node* head, int data){
    struct node* newnode=malloc(sizeof(struct node));
    newnode->data=data;
    newnode->link=NULL;
    return newnode;
}

struct node* insert_at_front(struct node* head, int data){
    struct node* newnode=createnode(newnode,data);
    newnode->link=head;
    head=newnode;
    return head;
}

struct node* insert_at_end(struct node* head, int data){
    struct node* temp=head;
    struct node* newnode=createnode(newnode,data);
    while(temp->link!=NULL){
        temp=temp->link;
    }
    temp->link=newnode;
    return head;
}

struct node* insert_at_pos(struct node* head, int data, int pos){
    struct node* newnode=createnode(newnode,data);
    struct node* temp1=head->link;
    struct node* temp=head;
    for(int i=0;i<pos;i++){
        temp=temp->link;
        temp1=temp1->link;
        pos--;
    }
    temp->link=newnode;
    newnode->link=temp1;
    return head;
}

struct node* delete_at_front(struct node* head){
    struct node* temp=head;
    head=head->link;
    free(temp);
    temp=NULL;
    return head;
}

struct node* delete_at_end(struct node* head){
    struct node* temp=head->link;
    struct node* temp1=head;
    while(temp->link!=NULL){
        temp=temp->link;
        temp1=temp1->link;
    }
    temp1->link=NULL;
    free(temp);
    temp=NULL;
    return head;
}

struct node* delete_at_pos(struct node* head, int pos){
    struct node* temp=head;
    struct node* temp1=head->link;
    for(int i=0;i<pos;i++){
        temp=temp->link;
        temp1=temp1->link;
        pos--;
    }
    temp->link=temp1->link;
    free(temp1);
    temp1=NULL;
    return head;
}

void display(struct node* head){
    struct node* temp=head;
    while(temp->link!= NULL){
        printf("%d  -> ", temp->data);
        temp=temp->link;
    }
    printf("\n");
}

int main() {
    struct node* head=malloc(sizeof(struct node));
    head=insert_at_front(head,30);
    head=insert_at_front(head,20);
    head=insert_at_front(head,10);
    head=insert_at_end(head,100);
    head=insert_at_pos(head,40,4);
    //head=delete_at_front(head);
    //head=delete_at_end(head);
    //head=delete_at_pos(head,2);
    display(head);
    return 0;
}
