struct Node{
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

        addToStart(key);
        return mp[key]->value;
    }
    
    void put(int key, int value) {
        if(mp.find(key) != mp.end()){
            Node* node = mp[key];
            node->value = value;
            addToStart(key);
        }    
        else{

            if(mp.size() == cap){
                Node* last = tail->prev;

                mp.erase(last->key);
                last->key = key;
                last->value = value;
                mp[key] = last;
                addToStart(key);
            }
            else{
                Node* newNode = new Node(key , value);

                Node* tempnext = head->next;
                head->next = newNode;
                newNode->prev = head;
                newNode->next = tempnext;
                tempnext->prev = newNode;

                mp[key] = newNode;
            }
        }
    }

    void addToStart(int key){
        Node* node = mp[key];

        Node* tempprev = node->prev;
        Node* tempnext = node->next;

        node->next = NULL;
        node->prev = NULL;

        tempprev->next = tempnext;
        tempnext->prev = tempprev;

        Node* nextHead = head->next;
        head->next = node;
        node->prev = head;
        node->next = nextHead;
        nextHead->prev = node;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */