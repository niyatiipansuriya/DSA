//NIYATI K. PANSURIYA
//202251080

#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

#define mx_vertices 100

int minDistance(int distance[], int visited[], int n) {
    int min = mx_vertices, mn_ind;

    for (int i = 0; i < n; i++) {
        if (!visited[i] && distance[i] < min) {
            min = distance[i];
            mn_ind = i;
        }
    }

    return mn_ind;
}

void Path(int parent[], int n, int source) {
    printf("Paths from source vertex %d:\n", source);
    printf("Vertex  Path\n");

    for (int i = 0; i < n; i++) {
        if (i != source && parent[i] != -1) {
            printf("%d      %d", i, i); 
            int j = i;
            while (parent[j] != -1) {
                printf(" <- %d", parent[j]);
                j = parent[j];
            }
            printf("\n");
        } else if (i != source) {
            printf("%d      %s\n", i, "N/A");
        }
    }
}

void Distance(int distance[], int n, int source) {
    printf("Shortest distances from source vertex %d:\n", source);
    printf("Vertex  Distance\n");

    for (int i = 0; i < n; i++) {
        if (distance[i] == mx_vertices) {
            printf("%d          %s\n", i, "Infinite");
        } else {
            printf("%d          %d\n", i, distance[i]);
        }
    }
}

void dijkstra(int graph[mx_vertices][mx_vertices], int n, int source, int b) {
    int distance[mx_vertices];
    int visited[mx_vertices];
    int parent[mx_vertices];

    for (int i = 0; i < n; i++) {
        distance[i] = mx_vertices;
        visited[i] = 0;
        parent[i] = -1;
    }

    distance[source] = 0;

    for (int i = 0; i < n - 1; i++) {
        int k = minDistance(distance, visited, n);
        visited[k] = 1;

        for (int j = 0; j < n; j++) {
            if (!visited[j] && graph[k][j] != mx_vertices && distance[k] + graph[k][j] < distance[j]) {
                distance[j] = distance[k] + graph[k][j];
                parent[j] = k;
            }
        }
    }

    if (b == 0) {
        Path(parent, n, source);
    } else {
        Distance(distance, n, source);
    }
}

void prim(int graph[mx_vertices][mx_vertices], int n) 
    {
    int parent[mx_vertices];
    int key[mx_vertices];
    int mstSet[mx_vertices];

    for (int i = 0; i < n; i++) {
        key[i] = mx_vertices;
        mstSet[i] = 0;
    }

    key[0] = 0;
    parent[0] = -1;

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

    printf("Minimum Spanning Tree (Prim's Algorithm):\n");
    for (int i = 1; i < n; i++)
        printf("%d -> %d\n", parent[i], i);
}

int main() 
{
    int n;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    int graph[mx_vertices][mx_vertices];

    printf("\nEnter the weight of between nodes : (use only integer and 'N' , where 'N' represents no edje between those nodes)\n\n");

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {

            printf("Enter weight for the edge between %d, %d : ",i,j);
            char weight[5];
            scanf("%s", weight);

            if (weight[0] == 'N') {
                graph[i][j] = mx_vertices;
            } else {
                graph[i][j] = atoi(weight);
                if (graph[i][j] == 0 && weight[0] != '0') {
                    printf("Invalid input for the edge weight.\n");
                    return 1;
                }
            }
        }
    }

    int source;
    printf("\n\n");
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
