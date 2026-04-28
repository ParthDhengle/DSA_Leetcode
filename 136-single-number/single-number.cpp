class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n=nums.size();
        int start=nums[0];
        for(int i=1;i<n;i++){
            start=start^nums[i];
        }
        return start;
    }
};