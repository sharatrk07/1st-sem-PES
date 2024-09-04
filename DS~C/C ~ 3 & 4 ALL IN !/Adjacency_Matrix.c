#include<stdio.h>
#include<stdlib.h>
#define MAX_VERTICES 100

struct graph{
    int v;
    int adjMatrix[MAX_VERTICES][MAX_VERTICES];
};

struct graph* creategraph(int v){
    struct graph *graph=(struct graph*)malloc(sizeof (struct graph));
    graph->v=v;
    for(int i=0;i<v;++i){
        for(int j=0;j<v;++j){
            graph->adjMatrix[i][j]=0;
        }
    }
    return graph;
}

void addEdge (struct graph* graph,int src,int dest){
    graph->adjMatrix[src][dest]=1;
    graph->adjMatrix[dest][src]=1;
}

void printgraph(struct graph* graph ){
    printf("Adjacency Matrix Representation of the graph:\n");
    for(int i=0;i<graph->v;++i){
        for(int j=0; j<graph->v;++j)
        printf("%d  ",graph->adjMatrix[i][j]);
        printf("\n");
    }
}

int main(){
    int v=3;
    struct graph* graph=creategraph(v);
    addEdge (graph,0,1);
    addEdge(graph,0,2);
    addEdge(graph,2,1);

    printgraph(graph);
    return 0;
}