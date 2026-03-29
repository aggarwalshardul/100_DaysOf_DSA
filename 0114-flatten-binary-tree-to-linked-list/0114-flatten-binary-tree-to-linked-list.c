/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
// Helper function with prev pointer
void helper(struct TreeNode* root, struct TreeNode** prev) {
    if (root == NULL) return;

    // Reverse preorder: Right -> Left
    helper(root->right, prev);
    helper(root->left, prev);

    // Rewire pointers
    root->right = *prev;
    root->left = NULL;

    // Move prev
    *prev = root;
}

void flatten(struct TreeNode* root) {
    struct TreeNode* prev = NULL;
    helper(root, &prev);
}