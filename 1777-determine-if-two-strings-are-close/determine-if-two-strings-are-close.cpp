class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if(word1.size()!=word2.size()){
            return false;
        }
        unordered_map<char,int>map1;
        unordered_map<char,int>map2;
        unordered_set<int>s1,s2;
        for(char i:word1){
            map1[i]++;
            s1.insert(i);
        }
        for(char i:word2){
            map2[i]++;
            s2.insert(i);
        }
        unordered_map<int,int>hash_map;
        for(auto &i:map2){
            hash_map[i.second]++;
            if(!s1.count(i.first)){
                return false;
            }
        }

        for(auto &i:map1){
            if(!s2.count(i.first)){
                return false;
            }
            if(hash_map[i.second]){
                hash_map[i.second]--;
            }else{
                return false;
            }
        }
        return true;
    }
};