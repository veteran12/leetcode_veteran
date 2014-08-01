/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        map<RandomListNode *, RandomListNode *> record;
        
        RandomListNode dummy(0);
        RandomListNode *p = &dummy;
        RandomListNode *q = head;
        
        while(q != NULL) {
            RandomListNode *tmp = new RandomListNode(q->label);
            p->next = tmp;
            record[q] = p->next;
            p = p->next;
            q = q->next;
        }
        
        p = dummy.next;
        q = head;
        while(p != NULL) {
            p->random = record[q->random];
            p = p->next;
            q = q->next;
        }
        return dummy.next;
    }
};