struct Node{
    int key;
    int val;
    Node* prev;
    Node* next;

    Node (int key, int val){
        this->val = val;
        this->key = key;
        prev=NULL;
        next=NULL;
    } 
};
class LRUCache {
int cap;
unordered_map<int, Node*> kv;
Node* start;
Node* end;
public:
    LRUCache(int capacity) {
        this->cap = capacity;
        kv.clear();
        start = new Node(-1,-1);
        end = new Node(-1,-1);
        start->next = end;
        end->prev= start;
    }
    
    int get(int key) {
        if(!kv.count(key)){
            return -1;
        }

        Node* node =kv[key];
        del(node);
        insert(node);
        return node->val;
    }
    
    void put(int key, int val) {
        if(kv.count(key)){
            Node* node =kv[key];
            del(node);
            insert(node);
            node->val = val;
            return;
        }

        if(kv.size()>=cap){
            Node* node = end->prev;
            cout<<node->val<<endl;
            kv.erase(node->key);
            del(node);
            // delete node;
        }

        Node* node = new Node(key, val);
        kv[key] = node;
        insert(node);
        return; 

    }

    void insert(Node* node){
        Node* nxt=start->next;
        start->next = node;
        node->prev = start;
        node->next = nxt;
        nxt->prev = node;
    }

    void del(Node* node){
        Node* previous = node->prev;
        Node* nxt= node->next;

        previous->next=nxt;
        nxt->prev = previous;
    }
};
/*
cap = 2;
lRUCache.put(1, 10);  // cache: {1=10}
lRUCache.get(1);      // return 10
lRUCache.put(2, 20);  // cache: {1=10, 2=20}
lRUCache.put(3, 30);  // cache: {2=20, 3=30}, key=1 was evicted
lRUCache.get(2);      // returns 20 
lRUCache.get(1);      // return -1 (not found)

-1<->2<->3<->-1
*/