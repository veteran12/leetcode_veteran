/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//use breadth first search, at the end of each level insert a NULL to indicate the end of each level
class Solution {
public:
    vector<vector<int> > levelOrder(TreeNode *root) {
        vector<vector<int> > res;
        if( root == NULL )
            return res;
        
        vector<int> tmp;
        queue<TreeNode *> que;
        que.push(root);
        que.push(NULL);
        
        TreeNode *node;
        while(que.size() > 0){
            node = que.front();
            que.pop();
            if(node == NULL){
                res.push_back(tmp);
                tmp.clear();
                if(que.size() > 0)
                    que.push(NULL);
                continue;
            }
            tmp.push_back(node->val);
            if(node->left)
                que.push(node->left);
            if(node->right)
                que.push(node->right);
        }
        return res;
    }
};

/*
 *python version
# Definition for a  binary tree node
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    # @param root, a tree node
    # @return a list of lists of integers
    def levelOrder(self, root):
        if root == None:
            return []
        res = []
        que = [ root, 0 ]
        tmp = []
        
        while len(que) > 0:
            node = que[0]
            que.pop(0)
            if node == 0:
                res.append(tmp)
                tmp = []
                if len(que) > 0:
                    que.append(0)
                continue
            tmp.append(node.val)
            if node.left:
                que.append(node.left)
            if node.right:
                que.append(node.right)
        return res
 *
 */