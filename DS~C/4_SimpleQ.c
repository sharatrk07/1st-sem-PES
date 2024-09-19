#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node* newnode(int data) {
    struct node* node = malloc(sizeof(struct node));
    node->data = data;
    node->next = NULL;
    return node;
}

struct Queue {
    struct node *front, *rear;
};

struct Queue* createQueue() {
    struct Queue* queue = malloc(sizeof(struct Queue));
    queue->front = queue->rear = NULL;
    return queue;
}

void enqueue(struct Queue* queue, int data) {
    struct node* new = newnode(data);    
    if (queue->rear == NULL) {
        queue->front = queue->rear = new;
        return;
    }
    queue->rear->next = new;
    queue->rear = new;
}

int dequeue(struct Queue* queue) {
    if (queue->front == NULL) {
        printf("Queue is empty\n");
        return -1;
    }
    struct node* temp = queue->front;
    int data = temp->data;
    queue->front = queue->front->next;

    free(temp);
    return data;
}

void display(struct Queue* queue) {
    if (queue->front == NULL) {
        printf("Queue is empty\n");
        return;
    }
    struct node* temp = queue->front;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct Queue* queue = createQueue();
    enqueue(queue, 1);
    enqueue(queue, 2);
    enqueue(queue, 3);
    printf("Queue: ");
    display(queue); 

    printf("Dequeued element: %d\n", dequeue(queue)); 
    printf("Dequeued element: %d\n", dequeue(queue)); 
    printf("Queue after dequeue: ");
    display(queue); 
    return 0;
}
