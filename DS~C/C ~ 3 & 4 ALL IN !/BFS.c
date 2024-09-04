#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Queue {
    struct Node *front, *rear;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct Queue* createQueue() {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->front = queue->rear = NULL;
    return queue;
}

int isEmpty(struct Queue* queue) {
    return (queue->front == NULL);
}

void enqueue(struct Queue* queue, int data) {
    struct Node* newNode = createNode(data);
    if (isEmpty(queue)) {
        queue->front = queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
}

int dequeue(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return -1;
    }
    struct Node* temp = queue->front;
    int data = temp->data;
    queue->front = temp->next;
    free(temp);
    return data;
}

int main() {
    struct Queue* queue = createQueue();

    int node, i = 1;
    int visited[7] = {0, 0, 0, 0, 0, 0, 0};
    int a[7][7] = {
        {0, 1, 1, 1, 0, 0, 0},
        {1, 0, 1, 0, 0, 0, 0},
        {1, 1, 0, 1, 1, 0, 0},
        {1, 0, 1, 0, 1, 0, 0},
        {0, 0, 1, 1, 0, 1, 1},
        {0, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 1, 0, 0}
    };
    printf("%d ", i);
    visited[i] = 1;
    enqueue(queue, i); // Enqueue i for exploration
    while (!isEmpty(queue)) {
        int node = dequeue(queue);
        for (int j = 0; j < 7; j++) {
            if (a[node][j] == 1 && visited[j] == 0) {
                printf("%d ", j);
                visited[j] = 1;
                enqueue(queue, j);
            }
        }
    }
    return 0;
}