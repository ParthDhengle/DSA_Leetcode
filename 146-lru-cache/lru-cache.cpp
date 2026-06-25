class LRUCache {
    struct Node{
        int key,val;
        Node* prev,*next;
        Node(int k,int v) : key(k),val(v),prev(NULL),next(NULL){}
    };
    int cap;
    unordered_map<int,Node*>mp;
    Node* head=new Node(-1,-1);
    Node* tail=new Node(-1,-1);
    
public:
    LRUCache(int capacity) {
        cap=capacity;
        head->next=tail;
        tail->prev=head;
    }
    void add(Node* addNode){
        Node* temp=head->next;
        addNode->next=temp;
        addNode->prev=head;
        temp->prev=addNode;
        head->next=addNode;
    }

    void del(Node* delNode){
        Node * prev=delNode->prev;
        Node* next=delNode->next;
        prev->next=next;
        next->prev=prev;
    }
    
    int get(int key) {
        if(mp.find(key)!=mp.end()){
            Node* resNode=mp[key];
            int res=resNode->val;
            del(resNode);
            add(resNode);
            return res;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end()){
            Node* existingNode=mp[key];
            mp.erase(key);
            del(existingNode);
            delete existingNode;            
        }
        if(cap==mp.size()){
            Node* remNode=tail->prev;
            mp.erase(remNode->key);
            del(remNode);
            delete remNode;
        }
        Node* nn=new Node(key,value);
        add(nn);
        mp[key]=nn;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */