/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int cameras = 0;

// DFS function
int dfs(struct TreeNode* root) {
    if (root == NULL) return 2; // null nodes are covered

    int left = dfs(root->left);
    int right = dfs(root->right);

    // If any child is not covered → place camera here
    if (left == 0 || right == 0) {
        cameras++;
        return 1; // has camera
    }

    // If any child has camera → this node is covered
    if (left == 1 || right == 1) {
        return 2; // covered
    }

    // Otherwise, this node is not covered
    return 0;
}

int minCameraCover(struct TreeNode* root) {
    cameras = 0; // reset global

    // If root is not covered → add camera
    if (dfs(root) == 0) {
        cameras++;
    }

    return cameras;
}