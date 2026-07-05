class Node{
public:
    int key;
    int val;
    Node* prev;
    Node* next;

    Node(int k, int v) : key(k), val(v),
        prev(nullptr), next(nullptr) {}
    
};

class LRUCache {
private:
    int cap;
    unordered_map<int, Node*> cache;
    Node* left;
    Node* right;

    void insert(Node* node) {
        // insert node into doubly linked list
        Node* prev = right->prev;
        prev->next = node;
        node->prev = prev;
        node->next = right;
        right->prev = node;
    }

    void remove(Node* node) {
        // remove node from doubly linkedlist
        Node* prv = node->prev;
        Node* nxt = node->next;
        prv->next = nxt;
        nxt->prev = prv;
    }

public:
    LRUCache(int capacity) {
        cap = capacity;
        cache.clear();
        left = new Node(0, 0);
        right = new Node(0, 0);
        left->next = right;
        right->prev = left;
    }
    
    int get(int key) {
        if (cache.find(key) != cache.end()) {
            Node* node = cache[key];
            remove(node);
            insert(node);
            return node->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            Node* node = cache[key];
            remove(node);
            insert(node);
            node->val = value;
            return;
        }

        Node* node = new Node(key, value);
        insert(node);
        cache[key] = node;

        if (cache.size() > cap) {
            Node* lru = left->next;
            remove(lru);
            cache.erase(lru->key);
            delete lru; // free the memory
        }
    }
};
