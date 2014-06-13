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
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        ListNode dummy(0);
        dummy.next = head;
        ListNode *p = &dummy;
        ListNode *q = &dummy;
        
        for (int i=0; i<m-1; i++)
            p = p->next;
        for (int j=0; j<n; j++)
            q = q->next;
        
        while (p->next != q) {
            ListNode *tmp = p->next;
            p->next = p->next->next;
            tmp->next = q->next;
            q->next = tmp;
        }
        return dummy.next;
    }
};