class Trie {
public:
 vector<string>tri;
    Trie() {
       
    }
    
    void insert(string word) {
        tri.push_back(word);
    }
    
    bool search(string word) {
        int n=tri.size();
        for(int i=0;i<n;i++){
            if(tri[i]==word){return true;}
        }return false;
    }
    
    bool startsWith(string prefix) {
        int n=tri.size();
        int pfx_sz=prefix.size();
        for(int i=0;i<n;i++){
            if(prefix== tri[i].substr(0,pfx_sz)){
                return true;
            }
        }
        return false;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */