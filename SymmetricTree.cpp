class Solution {
public:
    bool isSymmetric(TreeNode *root) {
        if (root == NULL)
            return true;
        return sub(root->left, root->right);
    }
    bool sub(TreeNode *leftChild, TreeNode *rightChild) {
        if (leftChild == NULL && rightChild==NULL)
            return true;
        if (leftChild != NULL && rightChild==NULL)
            return false;
        if (leftChild == NULL && rightChild!=NULL)
            return false;;
        if (leftChild->val != rightChild->val) 
            return false;
        return sub(leftChild->left, rightChild->right) && sub(leftChild->right, rightChild->left);
    }
};