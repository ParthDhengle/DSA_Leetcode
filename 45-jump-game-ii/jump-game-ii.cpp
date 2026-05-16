class Solution {
public:
int jumpr(int i,vector<int>& nums, vector<int>&dp, int n){
        if(i>=n-1){return 0;}
        if(nums[i]==0)return 100000;
        if(dp[i]!=100000){return dp[i];}
        for(int j=1;j<=nums[i];j++){
            dp[i]=min(dp[i],jumpr(i+j,nums,dp,n)+1);
        }
        return dp[i];
    }
    int jump(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,100000);
        return jumpr(0,nums,dp,n);
    }
};