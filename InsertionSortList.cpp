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
    ListNode *insertionSortList(ListNode *head) {
        if(head == NULL)
            return head;
        ListNode dummy(0);
        ListNode *p = &dummy;
        
        p->next = head;
        head = head->next;
        p->next->next = NULL;
        
        while(head != NULL) {
            ListNode *q = &dummy;
            while(q->next != NULL && q->next->val <= head->val) {
                    q = q->next;
                    continue;
            }
            ListNode *tmp = q->next;
            q->next = head;
            head = head->next;
            q->next->next = tmp;
        }
        return dummy.next;
    }
};