/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int min(int x, int y)
{
    return x < y? x : y;
}

int max(int x, int y)
{
    return x > y ? x : y;
}
int minDepth(struct TreeNode* root){
    if (!root)
        return 0;
    if (!root->left || !root->right)
        return 1 + max( minDepth(root->left), minDepth(root->right));
    return 1 + min( minDepth(root->left), minDepth(root->right));
}

