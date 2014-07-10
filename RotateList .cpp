ListNode *rotateRight(ListNode *head, int k) {
        if (head == NULL)
            return head;
        ListNode *tmp = head;
        int count = 1;
        while (tmp->next != NULL) {
            count++;
            tmp = tmp->next;
        }
        count = k % count;
        if (count == 0)
            return head;
        
        ListNode dummy(0);
        dummy.next = head;
        ListNode *p = &dummy;
        ListNode *q = &dummy;
        
        while (count > 0) {
            q = q->next;
            count--;
        }
        
        while (q->next != NULL) {
            q = q->next;
            p = p->next;
        }
        q->next = head;
        head = p->next;
        p->next = NULL;
        
        return head;
    }