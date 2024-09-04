#include <stdio.h>
#include <stdlib.h>

// Structure for a node in the graph
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to add an edge in an undirected graph
void addEdge(struct Node* graph[], int src, int dest) {
    struct Node* newNode = createNode(dest);
    newNode->next = graph[src];
    graph[src] = newNode;

    // Since the graph is undirected, add an edge from dest to src as well
    newNode = createNode(src);
    newNode->next = graph[dest];
    graph[dest] = newNode;
}

// Function to perform Breadth First Search
void BFS(struct Node* graph[], int start, int visited[]) {
    int queue[1000]; // Assuming maximum 1000 vertices
    int front = 0, rear = 0;

    visited[start] = 1;
    queue[rear++] = start;

    while (front < rear) {
        int current = queue[front++];
        printf("%d ", current);

        struct Node* temp = graph[current];
        while (temp != NULL) {
            if (!visited[temp->data]) {
                visited[temp->data] = 1;
                queue[rear++] = temp->data;
            }
            temp = temp->next;
        }
    }
}

// Function to perform Depth First Search
void DFS(struct Node* graph[], int vertex, int visited[]) {
    printf("%d ", vertex);
    visited[vertex] = 1;

    struct Node* temp = graph[vertex];
    while (temp != NULL) {
        if (!visited[temp->data]) {
            DFS(graph, temp->data, visited);
        }
        temp = temp->next;
    }
}

int main() {
    int vertices = 5; // Example: 5 vertices
    struct Node* graph[vertices];
    int i;
    for (i = 0; i < vertices; i++) {
        graph[i] = NULL;
    }

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 3);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 4);
    addEdge(graph, 4, 3);

    printf("Breadth First Search (BFS): ");
    int visitedBFS[vertices];
    for (i = 0; i < vertices; i++) {
        visitedBFS[i] = 0;
    }
    BFS(graph, 0, visitedBFS);
    printf("\n");

    printf("Depth First Search (DFS): ");
    int visitedDFS[vertices];
    for (i = 0; i < vertices; i++) {
        visitedDFS[i] = 0;
    }
    DFS(graph, 0, visitedDFS);
    printf("\n");

    return 0;
}