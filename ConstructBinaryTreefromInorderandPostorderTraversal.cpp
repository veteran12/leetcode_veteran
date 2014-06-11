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
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        return sub(inorder,postorder,0,inorder.size()-1,0,postorder.size()-1);
    }
    TreeNode *sub(vector<int> &inorder, vector<int> &postorder, int is, int ie, int ps, int pe ) {
        if ( is>ie )
            return NULL;
        
        TreeNode *tmp;
        int x = postorder[pe];
        tmp = new TreeNode(x);
        
        int i = 0;
        while(inorder[is+i] != x)
            i++;
        
        tmp->left = sub(inorder,postorder,is,is+i-1,ps,ps+i-1);
        tmp->right = sub(inorder,postorder,is+i+1,ie,ps+i,pe-1);
        
        return tmp;
    }
};