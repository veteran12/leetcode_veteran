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
    bool isValidBST(TreeNode *root) {
        return sub(root, INT_MIN, INT_MAX);
    }
    bool sub(TreeNode *root, int l, int r) {
        if (root == NULL)
            return true;
        else if (root->val > l && root->val < r)
            return sub(root->left, l, root->val) && sub(root->right, root->val, r);
        else
            return false;
    }
};

/*
 *python version
 *class Solution:
    # @param root, a tree node
    # @return a boolean
    def isValidBST(self, root):
        return self.sub(root, -2147483, 2147483647)
    
    def sub(self, root, l, r):
        if not root:
            return True
        elif root.val > l and root.val < r:
            return self.sub(root.left, l, root.val) and self.sub(root.right, root.val, r)
        else:
            return False
 */