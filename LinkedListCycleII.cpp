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
    ListNode *detectCycle(ListNode *head) {
        if(head == NULL)
            return NULL;
        ListNode dummy(0);
        dummy.next = head;
        ListNode *slow = &dummy;
        ListNode *fast = &dummy;
        
        while(fast != NULL && fast->next != NULL) {
            fast = fast->next->next;
            slow = slow->next;
            if(fast == slow) {
                ListNode *tmp = &dummy;
                while(tmp != slow) {
                    tmp = tmp->next;
                    slow = slow->next;
                }
                return tmp;
            }
        }
        return NULL;
    }
};