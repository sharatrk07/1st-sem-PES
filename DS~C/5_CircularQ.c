#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

typedef struct {
    Node* front;
    Node* rear;
} CircularQueue;

void initializeQueue(CircularQueue* queue) {
    queue->front = NULL;
    queue->rear = NULL;
}

int isEmpty(CircularQueue* queue) {
    return (queue->front == NULL);
}

void enqueue(CircularQueue* queue, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;

    if (isEmpty(queue)) {
        queue->front = newNode;
        queue->rear = newNode;
        newNode->next = newNode;
        newNode->prev = newNode;
    } else {
        newNode->next = queue->front;
        newNode->prev = queue->rear;
        queue->rear->next = newNode;
        queue->rear = newNode;
        queue->front->prev = newNode;
    }
}

int dequeue(CircularQueue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty.\n");
        return -1;
    }

    int data;
    Node* temp = queue->front;
    data = temp->data;

    queue->front = temp->next;
    queue->front->prev = queue->rear;
    queue->rear->next = queue->front;

    free(temp);
    return data;
}

void displayQueue(CircularQueue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty.\n");
        return;
    }

    Node* temp = queue->front;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != queue->front);
    printf("\n");
}

int main() {
    CircularQueue queue;
    initializeQueue(&queue);

    enqueue(&queue, 10);
    enqueue(&queue, 20);
    enqueue(&queue, 30);

    printf("Queued elements:  ");
    displayQueue(&queue);

    printf("Dequeued element: %d\n", dequeue(&queue));
    printf("Queue elements after dequeue: ");
    displayQueue(&queue);
    return 0;
}
