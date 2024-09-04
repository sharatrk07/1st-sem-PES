#include <stdio.h>
#include <stdlib.h>

struct node {
    int dest;
    struct node* next;
};

struct adjList {
    struct node* head;
};

struct graph {
    int vertices;
    struct adjList* array;
};

struct node* createnode(int dest) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->dest = dest;
    newnode->next = NULL;
    return newnode;
}

struct graph* creategraph(int vertices) {
    struct graph* graph = (struct graph*)malloc(sizeof(struct graph));
    graph->vertices = vertices;
    graph->array = (struct adjList*)malloc(vertices * sizeof(struct adjList));
    
    for (int i = 0; i < vertices; ++i)
        graph->array[i].head = NULL;
    
    return graph;
}

void addEdge(struct graph* graph, int src, int dest) {
    // Add edge from src to dest
    struct node* newnode = createnode(dest);
    newnode->next = graph->array[src].head;
    graph->array[src].head = newnode;
}

// Function to print the adjacency list representation of the graph
void printgraph(struct graph* g) {
    for (int v = 0; v < g->vertices; ++v) {
        struct node* temp = g->array[v].head;
        printf("Adjacency list of vertex %d\n", v);
        while (temp) {
            printf(" -> %d", temp->dest);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {
    int V = 5;
    struct graph* g = creategraph(V);
    addEdge(g, 0, 1);
    addEdge(g, 0, 4);
    addEdge(g, 1, 2);
    addEdge(g, 1, 3);
    addEdge(g, 1, 4);
    addEdge(g, 2, 3);
    addEdge(g, 3, 4);

    printgraph(g);
    return 0;
}