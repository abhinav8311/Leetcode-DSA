class LRUCache {
private:
    struct Node{
        int key;
        int val;
        Node* prev;
        Node* next;
        Node(int k, int v) : key(k), val(v), prev(NULL), next(NULL){}
    };

    int cap;
    unordered_map<int,Node*> cache;
    Node* head;
    Node* tail;

    void removeNode(Node* node){
        Node* p = node->prev;
        Node* n = node->next;
        p->next = n;
        n->prev = p;
    }

    void insertNodeAtHead(Node* node){
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }
public:
    LRUCache(int capacity) {
        cap = capacity;
        head = new Node(0,0);
        tail = new Node(0,0);
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if(cache.find(key) == cache.end()){
            return -1;
        }
        Node* node = cache[key];
        removeNode(node);
        insertNodeAtHead(node);

        return node->val;
    }
    
    void put(int key, int value) {
        if(cache.find(key) != cache.end()){
            Node* node = cache[key];
            removeNode(node);
            insertNodeAtHead(node);
            node->val = value;
        }
        else{
            if(cap == cache.size()){
                Node* lru = tail->prev;
                removeNode(lru);
                cache.erase(lru->key);
                delete lru;
            }
            Node* node = new Node(key,value);
            cache[key] = node;
            insertNodeAtHead(node);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */