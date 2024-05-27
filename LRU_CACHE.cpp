class LRUCache {
public:
    class node{
        public:
            int value;
            int key;
            node* pre;
            node* next;

            node(int k, int v) : key(k), value(v), pre(nullptr), next(nullptr) {}
    };
    int count;
    int capacity;
    unordered_map<int,node*>mp;
    node* head;
    node* tail;
    LRUCache(int capacity) {
        this->capacity = capacity;
        count=0;
        head = new node(-1, -1);
        tail = new node(-1, -1);
        head->next = tail;
        tail->pre = head;
    }
    void addnode(node* newNode){
        newNode->pre = head;
        newNode->next = head->next;
        head->next->pre = newNode;
        head->next = newNode;
    }
    void delnode(node* delNode) {
        node* preNode = delNode->pre;
        node* nextNode = delNode->next;

        preNode->next = nextNode;
        nextNode->pre = preNode;
    }
    
    int get(int key) {
        if(mp.count(key)){
            delnode(mp[key]);
            addnode(mp[key]);
            return mp[key]->value;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mp.count(key)){
            mp[key]->value = value;
            delnode(mp[key]);
            addnode(mp[key]);
        }
        else{
            node* curr = new node(key,value);
            curr->key=key;
            mp[key]=curr;
            addnode(curr);
            count++;

            if(count>capacity){
                node* least = tail->pre;
                mp.erase(least->key);
                delnode(least);
                delete least;
                count--;
            }
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
