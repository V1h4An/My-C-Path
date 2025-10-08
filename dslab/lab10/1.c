/*WAP to create an un-directed graph using Adjacency Matrix Method and display the 
degree of each vertex.*/
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 10


void createAdjMatrix(int adjMatrix[MAX_VERTICES][MAX_VERTICES], int vertices) {
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            adjMatrix[i][j] = 0;  
        }
    }

    int u, v, edges;
    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    for (int i = 0; i < edges; i++) {
        printf("Enter edge (u v): ");
        scanf("%d %d", &u, &v);
        adjMatrix[u][v] = 1;
        adjMatrix[v][u] = 1;
    }
}


void displayAdjMatrix(int adjMatrix[MAX_VERTICES][MAX_VERTICES], int vertices) {
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            printf("%d ", adjMatrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int vertices;
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);

    int adjMatrix[MAX_VERTICES][MAX_VERTICES];
    createAdjMatrix(adjMatrix, vertices);
    displayAdjMatrix(adjMatrix, vertices);

    return 0;
}
