#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* link;
}*top=NULL;

int isempty(){
    if(top==NULL)
        return 1;
    else
        return 0;
}

int ispeek(){
    if(isempty()){
        printf("Stack is empty");
    }    
    return top->data;
}

int push(int data){
    struct node* newnode=malloc(sizeof(struct node));
    newnode->data=data;
    newnode->link=NULL;
    newnode->link=top;
    top=newnode;
}

int pop(){
    if(isempty()){
        printf("Stack is empty");
    }  
    struct node* temp=top;
    int val=top->data;
    top=top->link;
    free(temp);
    return val;
}

void print(){
    struct node* temp=top;
    if(isempty()){
        printf("Stack is empty");
    }  
    while(temp!=NULL){
        printf("Elements are: %d\n", temp->data);
        temp=temp->link;
    }
}

int main(){
    int choice, data;
    while(1){
        printf("\n-------------------------------------------------\n");
        printf("1. PUSH\n");
        printf("2. POP\n");
        printf("3. PEEK\n");
        printf("4. Print all the elements\n");
        printf("5. EXIT\n");
        printf("Enter the choice: ");
        scanf("%d",&choice);
        
        switch(choice){
            case 1: printf("Enter element to be pushed: ");
                    scanf("%d",&data);
                    push(data);
                    break;
                    
            case 2: data=pop();
                    printf("Poppd element is: %d",data);
                    break;
                    
            case 3: printf("The topmost element is: %d\n",ispeek());
                    break;
                    
            case 4: print();
                    break;
            
            case 5: exit(1);
                    break;
                    
            default: printf("Wrong Input");
        }
    }
    return 0;
}