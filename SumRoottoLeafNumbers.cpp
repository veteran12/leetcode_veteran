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
    int sumNumbers(TreeNode *root) {
        if(!root)
            return 0;
        int sum = 0;
        sub(root, 0, sum);
        return sum;
    }
    
    void sub(TreeNode *root, int res, int &sum) {
        res = res * 10 + root->val;
        if(root->left == NULL && root->right == NULL) {
            sum += res;
            return;
        }
        
        if(root->left != NULL)
            sub(root->left, res, sum);
            
        if(root->right != NULL)
            sub(root->right, res, sum);
        return;
    }
};