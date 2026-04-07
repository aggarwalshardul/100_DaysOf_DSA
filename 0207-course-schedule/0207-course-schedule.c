#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool dfs(int node, int** adj, int* adjSize, int* state) {
    if (state[node] == 1) return true;   // cycle found
    if (state[node] == 2) return false;  // already safe

    state[node] = 1; // mark visiting

    for (int i = 0; i < adjSize[node]; i++) {
        int nei = adj[node][i];
        if (dfs(nei, adj, adjSize, state)) {
            return true;
        }
    }

    state[node] = 2; // mark safe
    return false;
}

bool canFinish(int numCourses, int** prerequisites, int prerequisitesSize, int* prerequisitesColSize) {
    
    // adjacency list
    int** adj = (int**)malloc(numCourses * sizeof(int*));
    int* adjSize = (int*)calloc(numCourses, sizeof(int));

    for (int i = 0; i < numCourses; i++) {
        adj[i] = (int*)malloc(numCourses * sizeof(int));
    }

    // build graph (b → a)
    for (int i = 0; i < prerequisitesSize; i++) {
        int a = prerequisites[i][0];
        int b = prerequisites[i][1];
        adj[b][adjSize[b]++] = a;
    }

    // state array
    int* state = (int*)calloc(numCourses, sizeof(int));

    // check each node
    for (int i = 0; i < numCourses; i++) {
        if (dfs(i, adj, adjSize, state)) {
            return false; // cycle exists
        }
    }

    return true;
}