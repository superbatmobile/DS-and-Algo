/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


bool isValidBST(struct TreeNode* root){
    if (!root)
        return true;
    struct TreeNode* arr[10005];
    int i = 0;
    struct TreeNode* cur = root;
    struct TreeNode* prev = NULL;
    while (cur || (i > 0)){
        while(cur){
            arr[i++] = cur;
            cur = cur->left;
        }
        cur = arr[--i];
        if (prev && prev->val >= cur->val)
            return false;
        prev = cur;
        cur = cur->right;
    }
    return true;   
}