class Solution {
public:
int recursion(int i,vector<int>&cost,vector<int>&dp){
    if(i>=cost.size()){
        return 0;
    }
    if(dp[i]!=-1){return dp[i];}

    dp[i]=cost[i]+min(recursion(i+1,cost,dp),recursion(i+2,cost,dp));
    return dp[i];
}
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int>dp(cost.size(),-1);

        return min(recursion(0,cost,dp),recursion(1,cost,dp));
    }
};