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
    ListNode *reverseKGroup(ListNode *head, int k) {
        ListNode dummy(0);
        dummy.next = head;
        ListNode *p = &dummy;
        ListNode *first = &dummy;
        while(p != NULL) {
            int i = k;
            while(p!=NULL && i>0) {
                p = p->next;
                i--;
            }
            if(p == NULL)
                return dummy.next;
            ListNode *second = p->next;
            p->next = NULL;
            first->next = sub(first->next);
            while(first->next != NULL)
                first = first->next;
            first->next = second;
            p = first;
        }
        return dummy.next;
    }
    
    ListNode *sub(ListNode *head) {
        ListNode dummy(0);
        while(head != NULL) {
            ListNode *tmp = dummy.next;
            dummy.next = head;
            head = head->next;
            dummy.next->next = tmp;
        }
        return dummy.next;
    }
};