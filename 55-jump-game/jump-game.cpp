class Solution {
public:
    bool jump(int i,vector<int>& nums, vector<int>&dp, int n){
        if(i==n-1){return true;}
        if(dp[i]!=-1){return dp[i];}

        for(int j=1;j<=nums[i];j++){
            dp[i]=jump(i+j,nums,dp,n)?1:0;
            if(dp[i]==1){
                return true;
            }
        }
        return false;
    }
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,-1);
        return jump(0,nums,dp,n);
    }
};