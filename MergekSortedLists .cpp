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
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        if (lists.size() == 0)
            return NULL;
        while (lists.size() != 1) {
            ListNode *a = lists[0]; 
            ListNode *b = lists[1];
            lists.erase(lists.begin());
            lists.erase(lists.begin());
            ListNode *tmp = mergeTwo(a, b);
            lists.push_back(tmp);
        }
        return lists[0];
    }
    
    ListNode *mergeTwo(ListNode *a, ListNode *b) {
        ListNode res(0);
        ListNode *p = &res;
        while (a!=NULL && b!=NULL) {
            if (a->val <= b->val){
                p->next = a;
                a = a->next;
            }
            else {
                p->next = b;
                b = b->next;
            }
            p = p->next;
        }
        if (a != NULL)
            p->next = a;
        else
            p->next = b;
        return res.next;
    }
};


/*
 class Mycompare {
public:
    bool operator()(ListNode *a, ListNode *b) {
        return a->val > b->val;
    }
};

class Solution {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        priority_queue<ListNode *, vector<ListNode *>, Mycompare> q;
        for (int i = 0; i < lists.size(); ++i)
            if (lists[i])
                q.push(lists[i]);
        
        ListNode dummy(0), *cur = &dummy;
        while (!q.empty()) {
            ListNode *node = q.top();
            q.pop();
            cur = cur->next = node;
            if (node->next)
                q.push(node->next);
        }
        return dummy.next;
    }
};
 */