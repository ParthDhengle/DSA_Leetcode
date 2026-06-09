class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        int n=nums.size();

        for(int i=0;i<n;i++){
            int curr=nums[i];
            if(mp.find(curr) !=mp.end()){
                if(abs(i-mp[curr]) <=k){
                    return true;
                }
            }
            mp[nums[i]]=i;
        }
        return false;
    }
};