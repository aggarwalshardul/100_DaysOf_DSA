/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
    if (root == NULL) {
        *returnSize = 0;
        return NULL;
    }

    // Allocate result arrays
    int capacity = 2000;
    int** result = (int**)malloc(capacity * sizeof(int*));
    *returnColumnSizes = (int*)malloc(capacity * sizeof(int));
    *returnSize = 0;

    // Queue (array of pointers)
    struct TreeNode** queue = (struct TreeNode**)malloc(capacity * sizeof(struct TreeNode*));
    int front = 0, rear = 0;

    // Start BFS
    queue[rear++] = root;

    while (front < rear) {
        int levelSize = rear - front;

        // Allocate space for this level
        result[*returnSize] = (int*)malloc(levelSize * sizeof(int));
        (*returnColumnSizes)[*returnSize] = levelSize;

        for (int i = 0; i < levelSize; i++) {
            struct TreeNode* node = queue[front++];

            result[*returnSize][i] = node->val;

            if (node->left)
                queue[rear++] = node->left;

            if (node->right)
                queue[rear++] = node->right;
        }

        (*returnSize)++;
    }

    return result;
}