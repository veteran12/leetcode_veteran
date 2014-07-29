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
    ListNode *partition(ListNode *head, int x) {
        ListNode first(0);
        ListNode second(0);
        
        ListNode *p = head;
        ListNode *m = &first;
        ListNode *n = &second;
        
        while(p != NULL) {
            if(p->val < x) {
                m->next = p;
                p = p->next;
                m = m->next;
                m->next = NULL;
            } else {
                n->next = p;
                p = p->next;
                n = n->next;
                n->next = NULL;
            }
        }
        
        m->next = second.next;
        
        return first.next;
    }
};