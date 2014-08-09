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
    ListNode *deleteDuplicates(ListNode *head) {
        if(head == NULL)
            return NULL;
        ListNode dummy(0);
        dummy.next = head;
        
        ListNode *p = &dummy;
        ListNode *q = head;
        
        while(q != NULL) {
            while(q->next && q->val==q->next->val)
                q = q->next;
            if(p->next == q) {
                p = p->next;
                q = q->next;
            }
            else {
                p->next = q->next;
                q = p->next;
            }
        }
        return dummy.next;
    }
    
};