#include <stdio.h>
#include <stdbool.h>

#define MAX_VERTICES 100

// Function for BFS
void BFS(int startVertex, int adjMatrix[MAX_VERTICES][MAX_VERTICES], int vertices) {
    bool visited[MAX_VERTICES] = {false};  // Keep track of visited vertices
    int queue[MAX_VERTICES];
    int front = 0, rear = 0;  // Initialize an empty queue

    // Mark the start vertex as visited and enqueue it
    visited[startVertex] = true;
    queue[rear++] = startVertex;

    while (front < rear) {
        int currentVertex = queue[front++];  // Dequeue the vertex
        printf("%d ", currentVertex);        // Visit the node

        // Enqueue all adjacent unvisited vertices
        for (int i = 0; i < vertices; i++) {
            if (adjMatrix[currentVertex][i] == 1 && !visited[i]) {
                visited[i] = true;
                queue[rear++] = i;
            }
        }
    }
}

int main() {
    int vertices = 4;
    int adjMatrix[MAX_VERTICES][MAX_VERTICES] = {
        {0, 1, 1, 0},
        {1, 0, 0, 1},
        {1, 0, 0, 1},
        {0, 1, 1, 0}
    };

    printf("BFS starting from vertex 0:\n");
    BFS(0, adjMatrix, vertices);
    return 0;
}
