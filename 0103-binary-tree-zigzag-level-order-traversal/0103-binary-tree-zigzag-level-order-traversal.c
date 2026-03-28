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
int** zigzagLevelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
    
    if (!root) {
        *returnSize = 0;
        return NULL;
    }

    int capacity = 10000;  // safe size
    struct TreeNode** queue = (struct TreeNode**)malloc(capacity * sizeof(struct TreeNode*));
    
    int front = 0, rear = 0;
    queue[rear++] = root;

    int** result = (int**)malloc(capacity * sizeof(int*));
    *returnColumnSizes = (int*)malloc(capacity * sizeof(int));

    int level = 0;
    int leftToRight = 1;

    while (front < rear) {
        
        int size = rear - front;
        result[level] = (int*)malloc(size * sizeof(int));
        (*returnColumnSizes)[level] = size;

        for (int i = 0; i < size; i++) {
            struct TreeNode* node = queue[front++];

            int index = leftToRight ? i : (size - i - 1);
            result[level][index] = node->val;

            if (node->left)
                queue[rear++] = node->left;
            if (node->right)
                queue[rear++] = node->right;
        }

        leftToRight = !leftToRight;
        level++;
    }

    *returnSize = level;
    return result;
}