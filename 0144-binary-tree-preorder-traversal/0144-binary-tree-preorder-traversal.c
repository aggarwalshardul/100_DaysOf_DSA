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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void preorder(struct TreeNode* root, int* arr, int* index) {
    if (root == NULL) return;

    arr[*index] = root->val;      // Root
    (*index)++;

    preorder(root->left, arr, index);   // Left
    preorder(root->right, arr, index);  // Right
}

int* preorderTraversal(struct TreeNode* root, int* returnSize) {
    int* result = (int*)malloc(1000 * sizeof(int));  // enough for constraints
    *returnSize = 0;

    preorder(root, result, returnSize);

    return result;
}