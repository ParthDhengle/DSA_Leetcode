class Solution {
public:
    int fn(int i, int j,string word1, string word2, vector<vector<int>>& dp){
        if (i<0)return j+1;
        if (j<0)return i+1;
        int min_op;
        if(dp[i][j]!=-1)return dp[i][j];

        if(word1[i]==word2[j]){return dp[i][j] = fn(i-1,j-1,word1,word2,dp);}

        int insrt= 1+ fn(i,j-1,word1,word2,dp);
        int del= 1+ fn(i-1,j,word1,word2,dp);
        int replace =1+ fn(i-1,j-1,word1,word2,dp);
        min_op=min(replace,min(insrt,del));
        return dp[i][j] = min_op;
    }
    int minDistance(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));

        return fn(n-1,m-1,word1,word2,dp);
    }
};