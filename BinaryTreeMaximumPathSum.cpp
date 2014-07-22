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
    int maxPathSum(TreeNode *root) {
        int tmp = root->val;
        sub(root, tmp);
        return tmp;
    }
    
    int sub(TreeNode *root, int &tmp) {
        if (root == NULL)
            return INT_MIN;
        
        int l = sub(root->left, tmp);
        int r = sub(root->right, tmp);
        int x = max(l, r);
        int m = root->val;
        
        if(l>0 && r>0)
            tmp = max(tmp, m+l+r);
        if (m >= 0) {
            tmp = max(tmp, max(m, m+x));
            m = max(m, m+x);
            return m;
        } else {
            tmp = max(tmp, m);
            tmp = max(tmp, x);
            if ( x > 0)
                return m + x;
            else
                return m;
        }
    }
};