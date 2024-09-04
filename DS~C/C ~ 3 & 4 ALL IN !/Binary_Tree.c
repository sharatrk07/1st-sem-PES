#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* left;
    struct node* right;
};

struct node *createnode (int data){
    struct node *newnode=(struct node*) malloc(sizeof(struct node));
    newnode->data=data;
    newnode->left=newnode->right=NULL;
    return newnode;
}

void inordertraversal(struct node* root){
    if(root!=NULL){
        inordertraversal(root->left);
        printf("%d  ",root->data);
        inordertraversal(root->right);
    }
}

int main(){
    struct node* root=createnode(4);
    root->left=createnode(2);
    root->right=createnode(6);
    root->left->left=createnode(1);
    root->left->right=createnode(3);
    root->right->left=createnode(5);
    root->right->right=createnode(7);
    printf("inorder traversal:");
    inordertraversal(root);
    printf("\n");
    return 0;
}