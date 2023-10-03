class Node{
    public:
    int value;
    int key;

    Node* next;
    Node* prev;

    Node(int key,int value){
        this->value = value;
        this->key = key;
        next = NULL;
        prev = NULL;
    }
};
class LRUCache {
public:
    int cap;
    map<int,Node*> mp;
    Node* head = new Node(-1,-1);
    Node* tail = new Node(-1,-1);

    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if(mp.find(key) == mp.end())return -1;

        int ans = mp[key]->value;
        deleteNode(key);
        addToStart(key , ans);

        return ans;
    }
    
    void put(int key, int value) {
        if(mp.find(key) != mp.end()){
            Node* node = mp[key];
            deleteNode(key);
            mp.erase(key);
        }    

        if(mp.size() == cap){
            Node* last = tail->prev;
            deleteNode(last->key);
        }

        addToStart(key , value);
    }

    void deleteNode(int key){
        Node* node = mp[key];

        Node* tempnext = node->next;
        Node* tempprev = node->prev;

        tempnext->prev = tempprev;
        tempprev->next = tempnext;

        mp.erase(key);
        delete(node);
    }
    void addToStart(int key , int value){
        Node* node = new Node(key , value);

        Node* nextHead = head->next;
        head->next = node;
        node->prev = head;
        node->next = nextHead;
        nextHead->prev = node;

        mp[key] = node;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */