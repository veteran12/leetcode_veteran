/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
    void reorderList(ListNode *head) {
        if ( head == NULL )
            return;
        ListNode *first,*second;
        ListNode dummy(0);
        dummy.next=head;
        first=second=&dummy;
        while(second!=NULL && second->next!=NULL){
            first=first->next;
            second=second->next->next;
        }
        second=first->next;
        first->next=NULL;   //need to split the list, so here set to NULL
        first=reverse(second);
        ListNode *p=head;
        ListNode *q=first;
        while(first!=NULL){
            q=first->next;
            first->next=p->next;
            p->next=first;
            p=p->next->next;
            first=q;
        }
    }
    
    ListNode * reverse(ListNode *head){
        if(head==NULL)
            return head;
        ListNode dummy(0);
        ListNode *p=head;
        ListNode *q=head;
        while(p!=NULL){
            q=p->next;
            p->next=dummy.next;
            dummy.next=p;
            p=q;
        }
        return dummy.next;
    }