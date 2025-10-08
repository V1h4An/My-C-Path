#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX_VERTICES 100

void DFSIterative(int startVertex, int adjMatrix[MAX_VERTICES][MAX_VERTICES], int vertices) {
    bool visited[MAX_VERTICES] = {false};  // Track visited vertices
    int stack[MAX_VERTICES];
    int top = -1;  // Initialize an empty stack

    // Push the starting vertex onto the stack
    stack[++top] = startVertex;

    while (top != -1) {
        int currentVertex = stack[top--];  // Pop the vertex from the stack

        if (!visited[currentVertex]) {
            printf("%d ", currentVertex);  // Visit the node
            visited[currentVertex] = true;
        }

        // Push all adjacent unvisited vertices onto the stack
        for (int i = 0; i < vertices; i++) {
            if (adjMatrix[currentVertex][i] == 1 && !visited[i]) {
                stack[++top] = i;
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

    printf("Iterative DFS starting from vertex 0:\n");
    DFSIterative(0, adjMatrix, vertices);

    return 0;
}
