class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>map1;
        unordered_map<int,int>map2;
        for(int i:nums1){map1[i]++;}
        for(int i:nums2){map2[i]++;}
        vector<int>a,b;
        for(auto &i:map1){
            if(map2[i.first]==0){
                a.push_back(i.first);
            }
        }
        for(auto &i:map2){
            if(map1[i.first]==0){
                b.push_back(i.first);
            }
        }
        return {a,b};
    }
};