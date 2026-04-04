class Solution {
public:
int recursion(int m,int n,int i,int j, vector<vector<int>>&dp){
    if(i==n-1 and j==m-1){
        return 1;
    }if(i >=n or j>=m){return 0;}
    if (dp[i][j]!=-1){return dp[i][j];}
    return dp[i][j]=recursion(m,n,i+1,j,dp)+recursion(m,n,i,j+1,dp);
}
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return recursion(m,n,0,0,dp);
    }
};