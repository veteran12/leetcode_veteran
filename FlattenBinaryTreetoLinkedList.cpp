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
    void flatten(TreeNode *root) {
        sub(root);
    }
    
    TreeNode *sub(TreeNode *root) {
        if(root == NULL) {
            return NULL;
        }
        
        TreeNode *ltmp = root->left;
        TreeNode *rtmp = root->right;
        TreeNode *llast = sub(root->left);
        TreeNode *rlast = sub(root->right);
        TreeNode *last = root;
        
        if(llast != NULL) {
            last->right = ltmp;
            root->left = NULL;
            last = llast;
        }
        
        if(rlast != NULL) {
            last->right = rtmp;
            last = rlast;
        }
        return last;
    }
    
};

class Solution {
public:
    void flatten(TreeNode *root) {
        flat(root);
    }
    void flat(TreeNode *root){
        if(root==NULL)
            return;
        if(root->left==NULL){
            flat(root->right);
        }else{
            TreeNode *tmp=root->right;
            root->right=root->left;
            root->left=NULL;
            flat(root->right);
            while(root->right!=NULL)
                root=root->right;
            root->right=tmp;
            flat(tmp);
        }
    }
};