/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int max(int a, int b);

bool isBalanced(struct TreeNode* root){
    bool res = true;
    tree_length(root, &res);
    return res;
}

int tree_length(struct TreeNode* node, bool *res)
{
    if (*res == false)
        return 0;
    if (!node)
        return 0;
    int left = tree_length(node->left, res);
    int right = tree_length(node->right, res);
    if (abs(left-right) > 1){
        *res = false;
        return 0;
    }
    return 1 + max(left,right);
    
}

int max(int a, int b)
{
    return a > b ? a : b;
}