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
    /*vector<int> postorderTraversal(TreeNode *root) {
        vector<int> res;
        sub(root, res);
        return res;
    }
    
    void sub(TreeNode *root, vector<int> &res) {
        if(root == NULL)
            return;
        sub(root->left, res);
        sub(root->right, res);
        res.push_back(root->val);
        return;
    }*/
    
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> res;
        stack<TreeNode *> first;
        stack<TreeNode *> second;
        
        TreeNode *tmp = root;
        
        while(tmp!=NULL || !first.empty()) {
            while(tmp!=NULL) {
                first.push(tmp);
                tmp = tmp->left;
            }
            tmp = first.top();
            if(!second.empty() && tmp == second.top()) {
                res.push_back(tmp->val);
                first.pop();
                second.pop();
                tmp = NULL;
                continue;
            }
            second.push(tmp);
            tmp = tmp->right;
        }
        return res;
    }
};