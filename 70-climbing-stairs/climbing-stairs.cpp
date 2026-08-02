class Solution {
public:
    int rec(int n,int curr,vector<int>&dp){
        if(curr==n)return 1;
        if(curr>n)return 0;
        if(dp[curr]>0)return dp[curr];
        int ans=rec(n,curr+1,dp);
        ans+=rec(n,curr+2,dp);
        dp[curr]=ans;
        return ans;
    }
    int climbStairs(int n) {
        vector<int>dp(n+1,0);
        return rec(n,0,dp);
    }
};