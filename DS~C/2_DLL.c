#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* prev;
    struct node* next;
};

struct node* createnode(struct node* head,int data){
    struct node* newnode=malloc(sizeof(struct node));
    newnode->data=data;
    newnode->prev=NULL;
    newnode->next=NULL; 
    head=newnode;
    return head;
}

struct node* insert_at_beg(struct node* head,int data){
    struct node* newnode=createnode(newnode, data); 
    newnode->next=head;
    head->prev=newnode;
    head=newnode;
    return head;
}

struct node* insert_at_pos(struct node* head,int data, int pos){
    struct node* temp=head;
    struct node* temp2=NULL;
    struct node* newnode=createnode(newnode, data);
    if(pos==0){
        insert_at_beg(newnode,data);
    }
    while(pos>1){
        temp=temp->next;
        pos--;
    }
    if(temp->next==NULL){
        temp->next=newnode;
        newnode->prev=temp;
    }
    else{
        temp2=temp->next;
        temp->next=newnode;
        temp2->prev=newnode;
        newnode->prev=temp;
        newnode->next=temp2;
    }
    return head;
}

struct node* insert_at_end(struct node* head,int data){
    struct node* temp=head;
    struct node* newnode=createnode(newnode,data);
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newnode;
    newnode->prev=temp;
    return head;
}

struct node* delete_at_front(struct node* head){
    struct node* temp=head;
    head=head->next;
    free(temp);
    temp=NULL;
    return head;
}

struct node* delete_at_end(struct node* head){
    struct node* temp=head;
    struct node* temp2=NULL;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp2=temp->prev;
    temp2->next=NULL;
    free(temp);
    temp=NULL;
    return head;
}

struct node* delete_at_pos(struct node* head, int pos){
    struct node* temp=head;
    struct node* temp2=NULL;
    if(pos==1){
        head=delete_at_front(head);
        return head;
    }
    while(pos>1){
        temp=temp->next;
        pos--;
    }
    if(temp->next==NULL){
        head=delete_at_end(head);
    }
    else{
        temp2=temp->prev;
        temp2->next=temp->next;
        (temp->next)->prev=temp2;
        free(temp);
        temp=NULL;
    }
    return head;
}

void display(struct node* head){
    struct node* temp=head;
    while(temp!=NULL){
        printf("Element is: %d\n", temp->data);
        temp=temp->next;
    }
    printf("\n");
}

int main(){
    struct node* head=NULL;
    head=createnode(head, 40);
    head=insert_at_beg(head,20);
    head=insert_at_beg(head,10);
    head=insert_at_pos(head,30, 2);
    head=insert_at_end(head,50);
    head=insert_at_end(head,60);
    head=delete_at_front(head);
    head=delete_at_end(head);
    head=delete_at_pos(head,2);
    display(head);
    return 0;
}
