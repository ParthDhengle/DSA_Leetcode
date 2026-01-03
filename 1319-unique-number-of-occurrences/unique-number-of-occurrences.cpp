class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int>map;
        unordered_set<int>s;

        for(int i:arr){
            map[i]++;
        }
        for(auto &i:map){
            s.insert(map[i.first]);
        }

        if(s.size()==map.size()){
            return true;
        }
        return false;
    }
};