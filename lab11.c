#include <stdio.h>
#include <stdlib.h>

#define MAX 100  // Maximum number of vertices

int adj[MAX][MAX];  // Adjacency matrix
int visited[MAX];   // Visited array to keep track of visited vertices
int queue[MAX];     // Queue for BFS
int front = -1, rear = -1;  // Front and rear for BFS queue

// Add an edge to the graph
void addEdge(int u, int v) {
    adj[u][v] = 1;  // Directed edge from u to v
}

// BFS function
void bfs(int startVertex, int numVertices) {
    int i;
    
    visited[startVertex] = 1;
    queue[++rear] = startVertex;  // Enqueue the start vertex

    while (front != rear) {
        int currentVertex = queue[++front];  // Dequeue
        printf("%d ", currentVertex);  // Print current vertex
        
        // Explore all adjacent vertices
        for (i = 0; i < numVertices; i++) {
            if (adj[currentVertex][i] == 1 && !visited[i]) {
                queue[++rear] = i;  // Enqueue adjacent vertex
                visited[i] = 1;  // Mark as visited
            }
        }
    }
}

// DFS function (recursive)
void dfs(int startVertex, int numVertices) {
    int i;
    visited[startVertex] = 1;  // Mark the current vertex as visited
    printf("%d ", startVertex);  // Print current vertex
    
    // Recursively visit all unvisited adjacent vertices
    for (i = 0; i < numVertices; i++) {
        if (adj[startVertex][i] == 1 && !visited[i]) {
            dfs(i, numVertices);  // Recursive DFS call
        }
    }
}

// Driver code to test BFS and DFS
int main() {
    int numVertices = 5;

    // Initialize the adjacency matrix and visited array
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            adj[i][j] = 0;
        }
        visited[i] = 0;
    }

    // Adding edges to the directed graph
    addEdge(0, 1);
    addEdge(0, 2);
    addEdge(1, 3);
    addEdge(2, 4);
    addEdge(3, 4);

    // Perform BFS
    printf("BFS starting from vertex 0: ");
    bfs(0, numVertices);
    
    // Reset visited array for DFS
    for (int i = 0; i < MAX; i++) {
        visited[i] = 0;
    }

    // Perform DFS
    printf("\nDFS starting from vertex 0: ");
    dfs(0, numVertices);

    return 0;
}

