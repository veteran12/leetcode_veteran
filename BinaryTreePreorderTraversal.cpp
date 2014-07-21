class Solution {
public:
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> res;
        stack<TreeNode *> sta;
        TreeNode *tmp = root;
        while (tmp!=NULL || !sta.empty()) {
            while (tmp!=NULL) {
                sta.push(tmp->right);
                res.push_back(tmp->val);
                tmp = tmp->left;
            }
            tmp = sta.top();
            sta.pop();
        }
        return res;
    }
};