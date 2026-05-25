
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct Edge {
    int src, dest, weight;
};


struct Graph {
    int V, E;
    struct Edge edges[MAX];
};

int parent[MAX];

int find(int i) {
    while (parent[i] != i)
        i = parent[i];
    return i;
}

void unionSet(int u, int v) {
    int u_root = find(u);
    int v_root = find(v);
    parent[u_root] = v_root;
}

int compare(const void *a, const void *b) {
    return ((struct Edge *)a)->weight -
           ((struct Edge *)b)->weight;
}

void kruskal(struct Graph g) {
    int i, count = 0;
    int totalCost = 0;


    qsort(g.edges, g.E, sizeof(g.edges[0]), compare);

    for (i = 0; i < g.V; i++)
        parent[i] = i;

    printf("Edges in MST:\n");

    for (i = 0; i < g.E && count < g.V - 1; i++) {
        int u = g.edges[i].src;
        int v = g.edges[i].dest;
        int w = g.edges[i].weight;


        if (find(u) != find(v)) {
            printf("%d -- %d == %d\n", u, v, w);
            totalCost += w;
            unionSet(u, v);
            count++;
        }
    }

    printf("Total Cost of MST = %d\n", totalCost);
}

int main() {
    struct Graph g;

    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &g.V, &g.E);

    printf("Enter edges (src dest weight):\n");

    for (int i = 0; i < g.E; i++) {
        scanf("%d %d %d",
              &g.edges[i].src,
              &g.edges[i].dest,
              &g.edges[i].weight);
    }

    kruskal(g);

    return 0;
}

