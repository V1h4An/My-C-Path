#include <stdio.h>
#include <stdbool.h>

#define MAX_VERTICES 100

// Recursive function for DFS
void DFS(int vertex, bool visited[], int adjMatrix[MAX_VERTICES][MAX_VERTICES], int vertices) {
    visited[vertex] = true;  // Mark the vertex as visited
    printf("%d ", vertex);   // Process the current vertex (visit)

    // Recursively visit all unvisited neighbors
    for (int i = 0; i < vertices; i++) {
        if (adjMatrix[vertex][i] == 1 && !visited[i]) {
            DFS(i, visited, adjMatrix, vertices);
        }
    }
}

int main() {
    int vertices = 4;
    bool visited[MAX_VERTICES] = {false};  // Keep track of visited vertices

    // Adjacency matrix representation of the graph
    int adjMatrix[MAX_VERTICES][MAX_VERTICES] = {
        {0, 1, 1, 0},
        {1, 0, 0, 1},
        {1, 0, 0, 1},
        {0, 1, 1, 0}
    };

    // Perform DFS starting from vertex 0
    printf("DFS starting from vertex 0:\n");
    DFS(0, visited, adjMatrix, vertices);

    return 0;
}
