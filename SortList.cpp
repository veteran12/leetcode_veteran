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
    ListNode *sortList(ListNode *head) {
        if(!head)
            return NULL;
        if(!head->next)
            return head;
        
        ListNode dummy(0);
        dummy.next = head;
        ListNode *p = &dummy;
        ListNode *q = &dummy;
        
        while(q!=NULL && q->next != NULL) {
            p = p->next;
            q = q->next->next;
        }
        
        q = p->next;
        p->next = NULL;
        p = dummy.next;
        
        p = sortList(p);
        q = sortList(q);
        
        ListNode *k = &dummy;
        while(p!=NULL && q!=NULL) {
            if(p->val <= q->val){
                k->next = p;
                p = p->next;
                k = k->next;
            }
            else {
                k->next = q;
                q = q->next;
                k = k->next;
            }
        }
        
        if(p != NULL)
            k->next = p;
        if(q != NULL) 
            k->next = q;
            
        return dummy.next;
    }
};