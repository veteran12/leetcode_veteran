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
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        vector<vector<int> > res;
        if(root == NULL)
            return res;
        queue<TreeNode *> que;
        que.push(root);
        que.push(NULL);
        
        vector<int> tmp;
        TreeNode *p;
        bool info = true;
        
        while(!que.empty()) {
            p = que.front();
            que.pop();
            if(p != NULL) {
                tmp.push_back(p->val);
                if(p->left != NULL)
                    que.push(p->left);
                if(p->right != NULL)
                    que.push(p->right);
            }
            else {
                if(info == false) {
                    reverse(tmp.begin(), tmp.end());
                    info = true;
                }
                else
                    info = false;
                res.push_back(tmp);
                tmp.clear();
                if(!que.empty()) 
                    que.push(NULL);
            }
        }
        return res;
    }
};