/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *p = l1;
        ListNode *q = l2;
        ListNode dummy(0);
        ListNode *res;
        res = &dummy;
        int carry = 0;
        
        while(p!=NULL && q!=NULL) {
            int tmp = (p->val + q->val + carry) % 10;
            carry = (p->val + q->val + carry) / 10;
            res->next = new ListNode(tmp);
            res = res->next;
            p = p->next;
            q = q->next;
        }
        
        while(p != NULL) {
            int tmp = (p->val + carry) % 10;
            carry = (p->val + carry) / 10;
            res->next = new ListNode(tmp);
            res = res->next;
            p = p->next;
        }
        
        while(q != NULL) {
            int tmp = (q->val + carry) % 10;
            carry = (q->val + carry) / 10;
            res->next = new ListNode(tmp);
            res = res->next;
            q = q->next;
        }
        
        if(carry != 0) {
            res->next = new ListNode(carry);
        }
        
        return dummy.next;
    }
};