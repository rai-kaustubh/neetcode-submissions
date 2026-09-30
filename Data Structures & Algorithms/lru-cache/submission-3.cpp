struct Node{
    int val, key;
    Node* prev;
    Node* next;

    Node(int key, int val){
        this->val = val;
        this->key = key;
        prev = NULL;
        next = NULL;
    }
};
class LRUCache {
int cap;
unordered_map<int, Node*> kv; //key->node*
Node* head=new Node(-1, -1);
Node* tail=new Node(-1,-1);
public:
    LRUCache(int capacity) {
        cap = capacity;
        kv.clear();
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if(!kv.count(key)) return -1;

        Node* add = kv[key];
        remove(add);
        insert(add);

        return add->val;
    }
    
    void put(int key, int value) {
        if(kv.count(key)){
            kv[key]->val = value;
            Node* add = kv[key];
            remove(add);
            insert(add);
            return;
        }

        if(kv.size()<cap){
            Node* node = new Node(key, value);
            insert(node);
            kv[key] = node;
            return;
        }
        int key_to_erase= tail->prev->key;
        kv.erase(key_to_erase);
        remove(tail->prev);
        Node* node = new Node(key, value);
        insert(node);
        kv[key] = node;
        return;
    }

    void insert(Node* node){
        Node* temp = head->next;
        head->next = node;
        node->prev = head;
        node->next = temp;
        temp->prev=node;
    }

    void remove(Node* node){
        Node* prev1 = node->prev;
        Node* next1 = node->next;
        prev1->next = next1;
        next1->prev = prev1;
    }
};
