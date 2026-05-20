class Solution {
public:
    int recursion(vector<int>& prices, int i, int n,int can_sell,vector<vector<int>>& dp){
        if(i>=n)return 0;
        if(dp[i][can_sell]!=-1){return dp[i][can_sell];}

        if(can_sell){
            int sell=prices[i] + recursion(prices,i+1,n,0,dp);
            int skip= recursion(prices,i+1,n,1,dp);
            return dp[i][1]=max(sell,skip);
        }
        else{            
            int buy=-prices[i] + recursion(prices,i+1,n,1,dp);
            int skip= recursion(prices,i+1,n,0,dp);
            return dp[i][0]= max(buy,skip);
        }
        return 0;
    }

    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return recursion(prices,0,n,0,dp);
    }
};