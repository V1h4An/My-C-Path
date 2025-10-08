#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 10

// Function to create an adjacency matrix for an undirected graph
void createAdjMatrix(int adjMatrix[MAX_VERTICES][MAX_VERTICES], int vertices) {
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            adjMatrix[i][j] = 0;  // Initialize matrix with 0 (no edges)
        }
    }

    int u, v, edges;
    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    for (int i = 0; i < edges; i++) {
        printf("Enter edge (u v): ");
        scanf("%d %d", &u, &v);
        adjMatrix[u][v] = 1; // Mark the edge in the matrix
        adjMatrix[v][u] = 1; // For undirected graph
    }
}

// Function to display the adjacency matrix
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
