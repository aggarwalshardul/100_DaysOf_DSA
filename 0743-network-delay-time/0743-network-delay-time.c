#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 10005

// Edge structure
typedef struct Node {
    int v, wt;
    struct Node* next;
} Node;

Node* adj[MAX];

// Create new node
Node* newNode(int v, int wt) {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->v = v;
    temp->wt = wt;
    temp->next = NULL;
    return temp;
}

// Add edge u -> v
void addEdge(int u, int v, int wt) {
    Node* temp = newNode(v, wt);
    temp->next = adj[u];
    adj[u] = temp;
}

// Min Heap structure
typedef struct {
    int node, dist;
} HeapNode;

HeapNode heap[MAX];
int size = 0;

// Swap
void swap(HeapNode* a, HeapNode* b) {
    HeapNode temp = *a;
    *a = *b;
    *b = temp;
}

// Heapify up
void heapifyUp(int i) {
    while (i > 0 && heap[i].dist < heap[(i - 1)/2].dist) {
        swap(&heap[i], &heap[(i - 1)/2]);
        i = (i - 1)/2;
    }
}

// Heapify down
void heapifyDown(int i) {
    int smallest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if (left < size && heap[left].dist < heap[smallest].dist)
        smallest = left;

    if (right < size && heap[right].dist < heap[smallest].dist)
        smallest = right;

    if (smallest != i) {
        swap(&heap[i], &heap[smallest]);
        heapifyDown(smallest);
    }
}

// Push to heap
void push(int node, int dist) {
    heap[size].node = node;
    heap[size].dist = dist;
    heapifyUp(size);
    size++;
}

// Pop min
HeapNode pop() {
    HeapNode root = heap[0];
    heap[0] = heap[size - 1];
    size--;
    heapifyDown(0);
    return root;
}

// Main function
int networkDelayTime(int** times, int timesSize, int* timesColSize, int n, int k) {

    // Initialize adjacency list
    for (int i = 1; i <= n; i++)
        adj[i] = NULL;

    // Build graph
    for (int i = 0; i < timesSize; i++) {
        int u = times[i][0];
        int v = times[i][1];
        int w = times[i][2];
        addEdge(u, v, w);
    }

    int dist[MAX];
    for (int i = 1; i <= n; i++)
        dist[i] = INT_MAX;

    dist[k] = 0;
    size = 0;
    push(k, 0);

    // Dijkstra
    while (size > 0) {
        HeapNode curr = pop();
        int node = curr.node;
        int d = curr.dist;

        Node* temp = adj[node];
        while (temp) {
            int next = temp->v;
            int wt = temp->wt;

            if (d + wt < dist[next]) {
                dist[next] = d + wt;
                push(next, dist[next]);
            }

            temp = temp->next;
        }
    }

    // Find max time
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (dist[i] == INT_MAX)
            return -1;
        if (dist[i] > ans)
            ans = dist[i];
    }

    return ans;
}