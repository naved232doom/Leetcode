class LRUCache {
public:
    class Node{
        public:
        Node* next;
        Node* prev;
        int key;
        int value;
        Node(int key,int value){
            this->key=key;
            this->value=value;
            next=NULL;
            prev=NULL;
        }
        
    };
    map<int,Node*> address;
    map<int,int> mp;
    Node* head;
    Node* tail;
    int max_size=0;
    int cur_size=0;
    LRUCache(int capacity) {
        max_size=capacity;
        head=new Node(-1,-1);
        tail=new Node(-1,-1);
        head->next=tail;
        tail->prev=head;
    }
    void LinkNodes(Node* &P,Node* &N){
        P->next=N;
        N->prev=P;
    }
    void moveNewNodeToHead(int key){
        Node* cur=address[key];
        Node* P=cur->prev;
        Node* N=cur->next;
        LinkNodes(P,N);
        
        N=head->next;
        // add cur node to head
        LinkNodes(head,cur);
        LinkNodes(cur,N);
    }
    int get(int key) {
        if(mp.find(key)==mp.end()) return -1;
        // fetch the value
        // move it towards the tail
        // isolate cur node
        moveNewNodeToHead(key);
        return mp[key];
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end()){
            mp[key]=value;
            moveNewNodeToHead(key);
            return;
        }
        Node* previous=tail->prev;
        //assert(previous->prev!=nullptr);
        Node* prev2=previous->prev;    
        if(cur_size==max_size){
            cur_size--;       
            LinkNodes(prev2,tail);
            mp.erase(previous->key);
            delete(previous);
        }
        
        Node* cur=new Node(key,value);
        Node* head_next=head->next;
        head->next=cur;
        cur->next=head_next;
        cur->prev=head;
        head_next->prev=cur;
        mp[key]=value;
        address[key]=cur;
        cur_size++;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */