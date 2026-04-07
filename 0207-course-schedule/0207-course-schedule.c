#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool canFinish(int numCourses, int** prerequisites, int prerequisitesSize, int* prerequisitesColSize) {
    
    int* indegree = (int*)calloc(numCourses, sizeof(int));
    int* adjSize = (int*)calloc(numCourses, sizeof(int));

    // Count outgoing edges first
    for (int i = 0; i < prerequisitesSize; i++) {
        int b = prerequisites[i][1];
        adjSize[b]++;
    }

    // Allocate exact memory (no waste)
    int** adj = (int**)malloc(numCourses * sizeof(int*));
    for (int i = 0; i < numCourses; i++) {
        adj[i] = (int*)malloc(adjSize[i] * sizeof(int));
        adjSize[i] = 0; // reset for reuse
    }

    // Build graph
    for (int i = 0; i < prerequisitesSize; i++) {
        int a = prerequisites[i][0];
        int b = prerequisites[i][1];
        adj[b][adjSize[b]++] = a;
        indegree[a]++;
    }

    // Queue (simple array)
    int* queue = (int*)malloc(numCourses * sizeof(int));
    int front = 0, rear = 0;

    // Push all indegree 0 nodes
    for (int i = 0; i < numCourses; i++) {
        if (indegree[i] == 0) {
            queue[rear++] = i;
        }
    }

    int count = 0;

    while (front < rear) {
        int node = queue[front++];
        count++;

        for (int i = 0; i < adjSize[node]; i++) {
            int nei = adj[node][i];
            if (--indegree[nei] == 0) {
                queue[rear++] = nei;
            }
        }
    }

    return count == numCourses;
}