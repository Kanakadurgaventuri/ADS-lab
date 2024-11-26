#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 5

// Global variables for graph representation
int graphMatrix[MAX_VERTICES][MAX_VERTICES];
int numVertices = MAX_VERTICES;

// Function to initialize the adjacency matrix
void initGraphMatrix()
{
    int i,j;
    for (i = 0; i<numVertices; i++)
    {
        for (j = 0; j<numVertices; j++)
        {
            graphMatrix[i][j] = 0;
        }
    }
}
void addEdgeMatrix(int u, int v)
{
    //undirected graph
    graphMatrix[u][v]=1;
    graphMatrix[v][u]=1;
}
void BFTMatrix(int start)
{
    int i;
    bool visited[MAX_VERTICES] = {false};
    int queue[MAX_VERTICES];
    int front =0,rear =0;
    visited[start] = true;
    queue[rear++]=start;
    printf("Breadth-First Traversal (BFT) starting from vertex %d: ", start);
    while(front < rear)
    {
        int cur = queue[front++];
        printf("%d ",cur);
        for(i=0;i<numVertices;i++)
        {
            if(graphMatrix[cur][i] && !visited[i])
            {
                visited[i]= true;
                queue[rear++] =i;
            }
        }
    }
    printf("\n");
}
void DFTMatrixRecursive(int vertex, bool visited[])
{
    int i;
    visited[vertex]=true;
    printf("%d ",vertex);
    for(i=0;i<numVertices;i++)
    {
        if(graphMatrix[vertex][i] && !visited[i])
        {
            DFTMatrixRecursive(i,visited);
        }
    }
}
void DFTMatrix(int start)
{
    bool visited[MAX_VERTICES]={false};
    printf("Depth-First Traversal (DFT) starting from vertex %d: ", start);
    DFTMatrixRecursive(start,visited);
    printf("\n");
}
int main()
{
    int i,j;
    initGraphMatrix();
    // Adding edges to the graph num Vertices
    addEdgeMatrix(0, 1);
    addEdgeMatrix(0, 2);
    addEdgeMatrix(1, 2);
    addEdgeMatrix(1, 3);
    addEdgeMatrix(2, 4);
    addEdgeMatrix(3, 4);
    printf("Adjacency Matrix\n");
    for(i=0;i<numVertices;i++)
    {
        for( j=0;j<numVertices;j++)
        {
            printf("%d  ",graphMatrix[i][j]);
        }
        printf("\n");
    }
    int startVertex =0;
    BFTMatrix(startVertex);
    DFTMatrix(startVertex);
    return 0;
}
