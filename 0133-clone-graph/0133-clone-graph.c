/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     int numNeighbors;
 *     struct Node** neighbors;
 * };
 */

#include <stdlib.h>

#define SIZE 1000

struct Node* orig[SIZE];
struct Node* cloneArr[SIZE];
int count = 0;

// Find index of node in map
int findIndex(struct Node* node) {
    for (int i = 0; i < count; i++) {
        if (orig[i] == node)
            return i;
    }
    return -1;
}

struct Node* cloneGraph(struct Node* node) {
    if (node == NULL) return NULL;

    // Check if already cloned
    int idx = findIndex(node);
    if (idx != -1)
        return cloneArr[idx];

    // Create new node
    struct Node* clone = (struct Node*)malloc(sizeof(struct Node));
    clone->val = node->val;
    clone->numNeighbors = node->numNeighbors;
    clone->neighbors = (struct Node**)malloc(node->numNeighbors * sizeof(struct Node*));

    // Store mapping
    orig[count] = node;
    cloneArr[count] = clone;
    count++;

    // Clone neighbors
    for (int i = 0; i < node->numNeighbors; i++) {
        clone->neighbors[i] = cloneGraph(node->neighbors[i]);
    }

    return clone;
}