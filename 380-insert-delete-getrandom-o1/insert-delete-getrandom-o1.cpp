class RandomizedSet {
public:
vector<int>hash;
unordered_map<int,int>mp;

    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(mp.find(val)!=mp.end()){return false;}
        hash.push_back(val);
        mp[val]=hash.size()-1;
        return true;
    }
    
    bool remove(int val) {
        if(mp.find(val)==mp.end()){return false;}
        int idx=mp[val];
        int last_ele=hash.back();

        hash[idx]=last_ele;
        mp[last_ele]=idx;

        hash.pop_back();
        mp.erase(val);
        return true;

    }
    
    int getRandom() {
        int idx=rand() % hash.size();
        return hash[idx];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */