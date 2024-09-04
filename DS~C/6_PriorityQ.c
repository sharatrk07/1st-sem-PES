#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    int priority;
    struct Node* next;
} Node;

Node* createNode(int data, int priority) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->priority = priority;
    newNode->next = NULL;
    return newNode;
}

void enqueue(Node** front, int data, int priority) {
    Node* newNode = createNode(data, priority);
    if (*front == NULL || priority < (*front)->priority) {
        newNode->next = *front;
        *front = newNode;
    } else {
        Node* current = *front;
        while (current->next != NULL && current->next->priority <= priority) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

int dequeue(Node** front) {
    if (*front == NULL) {
        printf("Queue is empty!\n");
        exit(1);
    }
    int data = (*front)->data;
    Node* temp = *front;
    *front = (*front)->next;
    free(temp);
    return data;
}

int peek(Node* front) {
    if (front == NULL) {
        printf("Queue is empty!\n");
        exit(1);
    }
    return front->data;
}

void display(Node* front) {
    if (front == NULL) {
        printf("Queue is empty!\n");
        return;
    }
    Node* current = front;
    while (current != NULL) {
        printf("(%d, %d) -> ", current->data, current->priority);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    Node* front = NULL;
    enqueue(&front, 10, 3);
    enqueue(&front, 20, 1);
    enqueue(&front, 30, 2);
    enqueue(&front, 40, 5);
    enqueue(&front, 50, 4);

    display(front);

    printf("Dequeueing: %d\n", dequeue(&front));
    printf("Peek: %d\n", peek(front));

    display(front);

    return 0;
}
