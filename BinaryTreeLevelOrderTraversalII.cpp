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
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        vector<vector<int> > res;
        if(root == NULL) 
            return res;
        
        queue<TreeNode *> que;
        que.push(root);
        que.push(NULL);
        
        TreeNode *tmp = NULL;
        vector<int> buffer;
        while(!que.empty()) {
            tmp = que.front();
            que.pop();
            if(tmp != NULL) {
                buffer.push_back(tmp->val);
                if(tmp->left != NULL)
                    que.push(tmp->left);
                if(tmp->right != NULL)
                    que.push(tmp->right);
            }
            else {
                res.push_back(buffer);
                buffer.clear();
                if(!que.empty())
                    que.push(NULL);
            }
            
        }
        reverse(res.begin(), res.end());
        
        return res;
    }
};