struct node {  
    node* pre;  
    int key;  
    int value;  
    node* next;  
    node(int k, int v):key(k),value(v),pre(NULL),next(NULL) {};  
}; 

class LRUCache{
public:
    int remain;
    node* head;
    node* tail;
    map<int,node *> val;
    
    LRUCache(int capacity) {
        if (capacity < 1) return;  
        head = new node(0, 0);  
        tail = new node(0, 0);  
        head->next = tail;  
        tail->pre = head;  
        val.clear();  
        //size = 0;  
        remain=capacity;  
    }
    
    int get(int key) {
        if(val.find(key)!=val.end()){
            node *tmp=val[key];
            tmp->pre->next=tmp->next;
            tmp->next->pre=tmp->pre;
            head->next->pre=tmp;
            tmp->next=head->next;
            head->next=tmp;
            tmp->pre=head;
            return val[key]->value;
        }
        else 
            return -1;
    }
    
    void set(int k, int v) {
        if(val.find(k)==val.end()){
            if(remain>0){
                node* tmp=new node(k,v); 
                val.insert(pair<int,node *>(k,tmp));
                head->next->pre=tmp;
                tmp->next=head->next;
                head->next=tmp;
                tmp->pre=head;
                remain--;
            }else{
                val.erase(tail->pre->key);
                tail->pre->pre->next=tail;
                tail->pre=tail->pre->pre;
                node* tmp=new node(k,v); 
                val.insert(pair<int,node *>(k,tmp));
                head->next->pre=tmp;
                tmp->next=head->next;
                head->next=tmp;
                tmp->pre=head;
            }
        }else{
            node* tmp=val[k];
            tmp->value=v;
            tmp->pre->next=tmp->next;
            tmp->next->pre=tmp->pre;
            head->next->pre=tmp;
            tmp->next=head->next;
            head->next=tmp;
            tmp->pre=head;
        }
    }
};