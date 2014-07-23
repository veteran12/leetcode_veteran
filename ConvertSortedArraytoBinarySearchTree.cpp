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
    TreeNode *sortedArrayToBST(vector<int> &num) {
        TreeNode *res = sub(num, 0, num.size()-1);
        return res;
    }
    
    TreeNode* sub(vector<int> &num, int start, int end) {
        if(start > end)
            return NULL;
        int x = (start + end) / 2;
        TreeNode *tmp = new TreeNode(num[x]);
        tmp->left = sub(num, start, x-1);
        tmp->right = sub(num, x+1, end);
        return tmp;
    }
};