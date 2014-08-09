/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    TreeNode *sortedListToBST(ListNode *head) {
        return sub(head, NULL);
    }
    
    TreeNode *sub(ListNode *head, ListNode *tail) {
        if(head == tail)
            return NULL;
        ListNode dummy(0);
        dummy.next = head;
        ListNode *first = &dummy;
        ListNode *second = &dummy;
        while(second != tail && second->next != tail) {
            first = first->next;
            second = second->next->next;
        }
        TreeNode *root = new TreeNode(first->val);
        root->left = sub(head, first);
        root->right = sub(first->next, tail);
        
        return root;
    }
    
};