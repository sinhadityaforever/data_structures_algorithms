class LRUCache {
public:
    
    class Node{
      public: 
        int key;
        int val;
        Node* next;
        Node* prev;
        Node(int _key, int _val){
            this->key = _key;
            this->val= _val;
        }
        
    };
    
    Node* head = new Node(-1,-1);
    Node* tail = new Node(-1,-1);
    int cap;
    unordered_map<int, Node*> mp;
    
    
    LRUCache(int capacity) {
        cap=capacity;
        head->next = tail;
        tail->prev = head;
    }
    
    void addNode(int key, int value){
        Node* tmpNext = head->next;
        Node* newNode = new Node(key, value);
        head->next = newNode;
        newNode->next = tmpNext;
        tmpNext->prev = newNode;
        newNode->prev = head;
    }
    
    
    void deleteNode(Node* node){
        Node* tmpPrev = node->prev;
        Node* tmpNext = node->next;
        tmpPrev->next = tmpNext;
        tmpNext->prev = tmpPrev;
    }
    
    int get(int key) {
        //if exists: update, then return
        if(mp.find(key)!=mp.end()){
            Node* node = mp[key];
            int val = node->val;
            //delete initial node
            deleteNode(node);
            mp.erase(key);
            //insert a new one
            addNode(key, val);
            mp[key]=head->next;
            return val;
        }
        else{
            return -1;
        }
        
        //if not: return -1
    }
    
    void put(int key, int value) {
        //if exists
        if(mp.find(key)!=mp.end()){
          //update  
            Node* node = mp[key];
            deleteNode(node);
            addNode(key, value);
            mp.erase(key);
            mp[key]=head->next;
        }
        
        else{
        
        if(mp.size()<cap){
           //if capacity left
            addNode(key, value);
            mp[key]=head->next;
        }
        else{
            int delKey = tail->prev->key;
            deleteNode(tail->prev);
            mp.erase(delKey);
            addNode(key, value);
            mp[key]=head->next;
            
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