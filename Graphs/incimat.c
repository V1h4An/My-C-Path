#include <stdio.h>

#define MAX_VERTICES 10
#define MAX_EDGES 20

// Function to create an incidence matrix for an undirected graph
void createIncidenceMatrix(int incidenceMatrix[MAX_VERTICES][MAX_EDGES], int vertices, int edges) {
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < edges; j++) {
            incidenceMatrix[i][j] = 0;  // Initialize matrix with 0
        }
    }

    int u, v;
    for (int i = 0; i < edges; i++) {
        printf("Enter edge %d (u v): ", i + 1);
        scanf("%d %d", &u, &v);
        incidenceMatrix[u][i] = 1; // Mark the vertex-edge incidence
        incidenceMatrix[v][i] = 1; // For undirected graph
    }
}

// Function to display the incidence matrix
void displayIncidenceMatrix(int incidenceMatrix[MAX_VERTICES][MAX_EDGES], int vertices, int edges) {
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < edges; j++) {
            printf("%d ", incidenceMatrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int vertices, edges;
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);
    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    int incidenceMatrix[MAX_VERTICES][MAX_EDGES];
    createIncidenceMatrix(incidenceMatrix, vertices, edges);
    displayIncidenceMatrix(incidenceMatrix, vertices, edges);

    return 0;
}
