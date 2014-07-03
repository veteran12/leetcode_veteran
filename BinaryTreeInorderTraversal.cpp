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
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> res;
        stack<TreeNode *> tmp;
        TreeNode *p = root;
        while (!tmp.empty() || p!=NULL) {
            while (p!=NULL) {
                tmp.push(p);
                p = p->left;
            }
            p = tmp.top();
            tmp.pop();
            res.push_back(p->val);
            p = p->right;
        }
        return res;
    }
};