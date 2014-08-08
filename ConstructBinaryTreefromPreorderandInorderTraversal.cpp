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
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        if(preorder.size() == 0)
            return NULL;
        return sub(preorder, inorder, 0, preorder.size()-1, 0, inorder.size()-1);
    }
    
    TreeNode * sub(vector<int> &preorder, vector<int> &inorder, int ls, int le, int rs, int re) {
        if(rs > re || ls > le)
            return NULL;
        
        TreeNode *root = new TreeNode(preorder[ls]);

        int i = rs;
        while(i<re && inorder[i] != preorder[ls])
            i++;
        root->left = sub(preorder, inorder, ls+1, ls+i-rs, rs, i-1);
        
        root->right = sub(preorder, inorder, ls+i-rs+1, le, i+1, re);
        
        return root;
    }
};