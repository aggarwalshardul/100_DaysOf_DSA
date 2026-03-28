/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* rightSideView(struct TreeNode* root, int* returnSize) {
    
    if (!root) {
        *returnSize = 0;
        return NULL;
    }

    int capacity = 10000;
    struct TreeNode** queue = malloc(capacity * sizeof(struct TreeNode*));
    
    int front = 0, rear = 0;
    queue[rear++] = root;

    int* result = malloc(capacity * sizeof(int));
    int level = 0;

    while (front < rear) {
        
        int size = rear - front;

        for (int i = 0; i < size; i++) {
            struct TreeNode* node = queue[front++];

            // last node of this level
            if (i == size - 1)
                result[level++] = node->val;

            if (node->left)
                queue[rear++] = node->left;
            if (node->right)
                queue[rear++] = node->right;
        }
    }

    *returnSize = level;
    return result;
}