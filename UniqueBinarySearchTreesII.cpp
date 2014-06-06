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
    vector<TreeNode *> generateTrees(int n){
        return generateTreesSub(1, n, n);
    }
    
    vector<TreeNode *> generateTreesSub(int low, int high, int n) {
        vector<TreeNode *> res;
        if( n == 0 ){
            res.push_back(NULL);
            return res;
        }
        if( n == 1 ){
            res.push_back( new TreeNode(high) );
            return res;
        }
        else{
            for(int k = low; k <= high; k++ ){
                vector<TreeNode *> leftTree = generateTreesSub(low, k - 1, k - low);
                vector<TreeNode *> rightTree = generateTreesSub(k + 1, high, high - k);
                for( int i = 0; i < leftTree.size(); i++ ){
                    for( int j = 0; j < rightTree.size(); j++ ){
                        TreeNode *tmp = new TreeNode(k);
                        tmp -> left = leftTree[i];
                        tmp -> right = rightTree[j];
                        res.push_back(tmp);
                    }
                }
            }
            return res;
        }
    }
};