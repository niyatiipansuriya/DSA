#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

#define MAX_VERTICES 100

int minDistance(int distance[], int visited[], int n) {
    int min = INT_MAX, min_index;

    for (int v = 0; v < n; v++) {
        if (!visited[v] && distance[v] < min) {
            min = distance[v];
            min_index = v;
        }
    }

    return min_index;
}

void Path(int parent[], int n, int source) {
    printf("Paths from source vertex %d:\n", source);
    printf("Vertex\tPath\n");

    for (int i = 0; i < n; i++) {
        if (i != source && parent[i] != -1) {
           printf("%d\t%d", i, i); 
            int j = i;
            while (parent[j] != -1) {
                printf(" <- %d", parent[j]);
                j = parent[j];
            }
            printf("\n");
        } else if (i != source) {
            printf("%d\t%s\n", i, "N/A");
        }
    }
}

void Distance(int distance[], int n, int source) {
    printf("Shortest distances from source vertex %d:\n", source);
    printf("Vertex\tDistance\n");

    for (int i = 0; i < n; i++) {
        if (distance[i] == INT_MAX) {
            printf("%d\t%s\n", i, "Infinite");
        } else {
            printf("%d\t%d\n", i, distance[i]);
        }
    }
}

void dijkstra(int graph[MAX_VERTICES][MAX_VERTICES], int n, int source, int b) {
    int distance[MAX_VERTICES];
    int visited[MAX_VERTICES];
    int parent[MAX_VERTICES];

    // Initialization
    for (int i = 0; i < n; i++) {
        distance[i] = INT_MAX;
        visited[i] = 0;
        parent[i] = -1;
    }

    // Correctly initialize the distance of the source vertex
    distance[source] = 0;

    // Main loop
    for (int count = 0; count < n - 1; count++) {
        int u = minDistance(distance, visited, n);
        visited[u] = 1;

        for (int v = 0; v < n; v++) {
            if (!visited[v] && graph[u][v] != INT_MAX && distance[u] + graph[u][v] < distance[v]) {
                distance[v] = distance[u] + graph[u][v];
                parent[v] = u;
            }
        }
    }
    // Print the solution

    if (b == 0) {
        Path(parent, n, source);
    } else {
        Distance(distance, n, source);
    }
}

void prim(int graph[MAX_VERTICES][MAX_VERTICES], int n) 
    {
    int parent[MAX_VERTICES];
    int key[MAX_VERTICES];
    int mstSet[MAX_VERTICES];

    // Initialization
    for (int i = 0; i < n; i++) {
        key[i] = INT_MAX;
        mstSet[i] = 0;
    }

    key[0] = 0;
    parent[0] = -1;

    // Main loop
    for (int count = 0; count < n - 1; count++) {
        int u = minDistance(key, mstSet, n);

        mstSet[u] = 1;

        for (int v = 0; v < n; v++) {
            if (graph[u][v] && mstSet[v] == 0 && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    // Print the Minimum Spanning Tree
    printf("\nMinimum Spanning Tree (Prim's Algorithm):\n");
    for (int i = 1; i < n; i++)
        printf("%d -> %d\n", parent[i], i);
}

int main() {
    int n;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    int graph[MAX_VERTICES][MAX_VERTICES];

    printf("Enter the adjacency matrix (use 'N' for no edge):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            char weight[5];
            scanf("%s", weight);

            if (weight[0] == 'N') {
                graph[i][j] = INT_MAX;
            } else {
                graph[i][j] = atoi(weight);
                if (graph[i][j] == 0 && weight[0] != '0') {
                    printf("Invalid input for edge weight.\n");
                    return 1;
                }
            }
        }
    }

    int source;
    printf("Enter the source vertex: ");
    scanf("%d", &source);

    printf("\n\n");
    dijkstra(graph, n, source , 1);

    printf("\n\n");

    dijkstra(graph, n, source , 0);

    printf("\n\n");
    prim(graph, n);

    return 0;
}
