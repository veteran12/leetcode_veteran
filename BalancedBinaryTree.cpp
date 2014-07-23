/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isBalanced(TreeNode *root) {
        if(root == NULL)
            return true;
        int l = depth(root->left);
        int r = depth(root->right);
        if(l-r > 1 || l-r < -1)
            return false;
        return isBalanced(root->left) && isBalanced(root->right);
        }
    
    int depth(TreeNode *root) {
        if(root == NULL)
            return 0;
        else
            return max(depth(root->left), depth(root->right)) + 1;
    }
};