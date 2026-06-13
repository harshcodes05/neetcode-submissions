class LRUCache {
    class Node {
        public:
        int key,val;
        Node* next;
        Node* prev;

        Node(int key, int val) : key(key), val(val), next(nullptr), prev(nullptr) {}
    };

public:
    Node left, right;
    int cap;
    unordered_map<int,Node*> m;
    LRUCache(int capacity): left(-1,-1), right(-1,-1) {
        cap = capacity;
        left.next = &right;
        right.prev = &left;
    }
    void insert(Node* node) {
        node->prev = right.prev;
        node->prev->next = node;
        node->next = &right;
        right.prev = node;
    }
    void remove(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }    
    int get(int key) {
        if(m.count(key)) {
            Node* node = m[key];
            remove(node);
            insert(node);
            return node->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(m.count(key)) {
            remove(m[key]);
            delete m[key];
            m.erase(key);
        }
        if((int)m.size()>=cap) {
            Node* toRemove = left.next;
            m.erase(toRemove->key);
            remove(toRemove);
            delete toRemove;
        }
        Node* node = new Node(key,value);
        insert(node);
        m[key] = node;
    }
};
