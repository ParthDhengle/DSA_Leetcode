class Solution {
public:
    void rec(vector<vector<int>>&ans, vector<int>& nums, int target, int sum, vector<int>&curr,int start){
        if(sum>target)return;
        if(sum==target){
            ans.push_back(curr);
            return;
        }
        for(int i=start;i<nums.size();i++){
            sum+=nums[i];
            curr.push_back(nums[i]);
            rec(ans,nums,target,sum,curr,i);
            sum-=nums[i];
            curr.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>curr;
        rec(ans,candidates,target,0,curr,0);
        return ans;
    }
};