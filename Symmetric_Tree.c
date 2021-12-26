/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void Symmetric(struct TreeNode* left, struct TreeNode* right, bool *res);

bool isSymmetric(struct TreeNode* root){
    if (!root){
        return true;
    }
    bool res = true;
    Symmetric(root->left, root->right, &res);
    return res;
}

void Symmetric(struct TreeNode* left, struct TreeNode* right, bool *res)
{
    if(!res)
        return ;
    if (!left && !right)
        return;
    if (!left || !right){
        *res = false;
        return;
    }
    if (left->val != right->val){
        *res = false;
        return;
    }
    Symmetric(left->right, right->left, res);
    Symmetric(left->left, right->right, res);
}