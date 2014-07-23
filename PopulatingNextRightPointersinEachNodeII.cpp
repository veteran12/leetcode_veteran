/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(root == NULL)
            return;
        queue<TreeLinkNode *> que;
        que.push(root);
        que.push(NULL);
        TreeLinkNode *tmp;
        
        while (!que.empty()) {
            tmp = que.front();
            que.pop();
            if(tmp) {
                tmp->next = que.front();
                if(tmp->left)
                    que.push(tmp->left);
                if(tmp->right)
                    que.push(tmp->right);
            } else {
                if (que.empty())
                    return;
                que.push(NULL);
            }
        }
    }
};