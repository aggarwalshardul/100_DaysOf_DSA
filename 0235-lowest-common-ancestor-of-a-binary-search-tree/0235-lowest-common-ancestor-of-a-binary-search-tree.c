/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    
    if (root == NULL) return NULL;

    // both nodes in left subtree
    if (p->val < root->val && q->val < root->val)
        return lowestCommonAncestor(root->left, p, q);

    // both nodes in right subtree
    if (p->val > root->val && q->val > root->val)
        return lowestCommonAncestor(root->right, p, q);

    // split point
    return root;
}