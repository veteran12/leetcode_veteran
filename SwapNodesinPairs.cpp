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
    ListNode *swapPairs(ListNode *head) {
        ListNode dummy(0);
        dummy.next = head;
        ListNode *p = &dummy;
        while (p->next!=NULL && p->next->next!=NULL) {
            ListNode *tmp1 = p->next->next->next;
            ListNode *tmp2 = p->next->next;
            tmp2->next = p->next;
            p->next->next = tmp1;
            p->next = tmp2;
            p = tmp2->next;
        }
        return dummy.next;
    }
};