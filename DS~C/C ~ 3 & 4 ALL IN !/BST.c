#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *left;
    struct node *right;
};

struct node* createNode(int data){
    struct node *n;
    n=(struct node*)malloc(sizeof(struct node));
    n->data=data;
    n->left=n->right=NULL;

    return n;
}

struct node* insert(struct node* root, int key){
    if(root == NULL)        return createNode(key);

    if(key < root->data)    root->left = insert(root->left,key);
    
    else                    root->right = insert(root->right,key);

    return root;
}

struct node* insertIteratively(struct node* root, int key) {
    struct node* new = createNode(key); // Make sure createNode() properly initializes the new node
    struct node* temp = root;
    struct node* prev = NULL;
    
    if (root == NULL) {
        root = new;
        return root;
    }
    
    while (temp != NULL) {
        prev = temp;
        if (key < temp->data)    temp = temp->left;
        else                     temp = temp->right;    
    }
    
    if (key < prev->data)    prev->left = new;
    else                     prev->right = new;

    return root;
}

struct node* minValInBST(struct node *root) {
    if(root == NULL) {
        printf("The tree is empty\n");
        return NULL;
    }

    if(root->right == NULL)    return root;

    return minValInBST(root->left);
}

struct node* deleteNodeInBST(struct node* root, int key){
    if(root == NULL)    return NULL;

    if(root->data == key){
        // 0 child
        if(root->left == NULL && root->right == NULL){
            free(root);
            return NULL;
        }

        // 1 child
        else if(root->left != NULL && root->right == NULL){
            struct node* temp = root->left;
            free(root);
            return temp;
        }

        else if(root->right != NULL && root->left == NULL){
            struct node* temp = root->right;
            free(root);
            return temp;
        }

        // 2 child node is used to get minimum value first go for right sub tree and then traverse left until leaf node
        else if(root->right != NULL && root->left != NULL){
            int minVal = minValInBST(root->right)->data;
            root->data = minVal;
            root->right = deleteNodeInBST(root->right,minVal);

            return root;
        }
        return root;
    }

    else if(key < root->data)           root->left = deleteNodeInBST(root->left,key);
     
    else                                root->right = deleteNodeInBST(root->right,key);

    return root;
}

struct node* searchInBST(struct node *root, int key){
    if(root == NULL){
        return NULL;
    }

    if(key < root->data)                return searchInBST(root->left,key);

    else if(key > root->data)           return searchInBST(root->right,key);

    else                                return root;
}

void preorder(struct node *root){
    if(root != NULL){
        printf("%d ",root->data);
        preorder(root->left);
        preorder(root->right);
    }

}

void inorder(struct node* root){
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void postorder(struct node *root){
    if(root != NULL){
        postorder(root->left);
        postorder(root->right);
        printf("%d " ,root->data);        
    }
}

int main(){
    struct node *root = NULL;

    root = insert(root,60);
    root = insert(root,20);
    root = insert(root,80);
    root = insert(root,10);
    root = insert(root,40);
    root = insert(root,70);
    root = insert(root,90);
    root = insert(root,30);
    root = insert(root,50);

    inorder(root);
    printf("\n\n");

    root = deleteNodeInBST(root,30);
    inorder(root);
    return 0;
}