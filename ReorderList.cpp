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
    void reorderList(ListNode *head) {
        if ( head == NULL )
            return;
            
        ListNode dummy(0);
        dummy.next = head;
        
        ListNode *p = &dummy;
        ListNode *q = &dummy;
        
        while(q!=NULL && q->next!=NULL) {
            p = p->next;
            q = q->next->next;
        }
        
        ListNode dummy1(0);
        q = p->next;
        p->next = NULL;
        
        while(q != NULL) {
            ListNode *tmp = dummy1.next;
            dummy1.next = q;
            q = q->next;
            dummy1.next->next = tmp;
        }
        
        p = dummy.next;
        q = dummy1.next;
        
        while(q!=NULL) {
            ListNode *tmp = p->next;
            p->next = q;
            q = q->next;
            p->next->next = tmp;
            p = tmp;
        }
        return;
    }
};