class Solution {
public:
    int rec(vector<int>&nums, int curr, vector<int>&dp){
        int n=nums.size();
        if(curr==n-1)return nums[curr];
        if(curr>=n)return 0;
        if(dp[curr]!=-1){return dp[curr];}
        int ans=max(rec(nums,curr+2,dp) + nums[curr], rec(nums,curr+1,dp)) ;
        dp[curr]=ans;
        return ans;
        
    }
    int rob(vector<int>& nums) {
        vector<int>dp(nums.size(),-1);
        return rec(nums,0,dp);
    }
};