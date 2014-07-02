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
    void recoverTree(TreeNode *root) {
        vector<TreeNode *> tmp;
        sub(tmp, root);
        TreeNode *first = NULL; 
        TreeNode *second = NULL;
        for (int i=1; i<tmp.size(); i++) {
            if (tmp[i]->val < tmp[i-1]->val) {
                if (first == NULL)
                    first = tmp[i-1];
                second = tmp[i];
            }
        }
        swap(first->val, second->val);
    }
    void sub(vector<TreeNode *> &tmp, TreeNode *root) {
        if (root == NULL)
            return;
        sub(tmp, root->left);
        tmp.push_back(root);
        sub(tmp, root->right);
        return;
    }
};