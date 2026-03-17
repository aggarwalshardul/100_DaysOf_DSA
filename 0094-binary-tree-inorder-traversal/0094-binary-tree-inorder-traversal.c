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

void inorder(struct TreeNode* root, int* arr, int* index) {
    if (root == NULL) return;

    inorder(root->left, arr, index);      // Left
    arr[*index] = root->val;              // Root
    (*index)++;
    inorder(root->right, arr, index);     // Right
}

int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    int* result = malloc(1000 * sizeof(int));  // enough for constraints
    *returnSize = 0;

    inorder(root, result, returnSize);

    return result;
}