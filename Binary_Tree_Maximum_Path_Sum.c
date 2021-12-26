/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int max(int left, int right);
int dfs(struct TreeNode* root, int *res);

int maxPathSum(struct TreeNode* root){
    int res = root->val;
    dfs(root, &res);
    return res;
}

int dfs(struct TreeNode* root, int *res)
{

    if (!root)
        return 0;

    
    int n = root->val;
    int left = root->left ? dfs(root->left, res) : 0;
    int right = root->right ? dfs(root->right, res) : 0;

    int temp = max( (n + left), (n+right));
    temp = max(n, temp);
    *res = max (temp, *res);
    *res = max ((n+left+right), *res);
    return temp;
}

int max(int left, int right)
{
    return left > right ? left : right;
}