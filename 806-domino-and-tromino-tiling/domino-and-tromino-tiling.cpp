class Solution {
public:
const int MOD=1000000007;
    int recursion(int r1,int r2,vector<vector<int>>&dp){
        if(r1==0 and r2==0){
            return 1;
        }
        if (r1<=0 or r2<=0)return 0; 
        if((r1==0 and r2==1)or(r1==1 and r2==0)){
            return 0;
        }
        if(dp[r1][r2]!=-1){return dp[r1][r2];}
        long long ans=0;
        if(r1==r2){
            ans+=recursion(r1-2,r2-2,dp);
            ans+=recursion(r1-1,r2-1,dp);
            ans+=recursion(r1-1,r2-2,dp);
            ans+=recursion(r1-2,r2-1,dp);
        }else if(r1>r2){
            ans+=recursion(r1-2,r2-1,dp);
            ans+=recursion(r1-2,r2,dp);
        }else{
            ans+=recursion(r1-1,r2-2,dp);
            ans+=recursion(r1,r2-2,dp);
        }
        return dp[r1][r2]=ans%MOD;
    }
    int numTilings(int n) {
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        int ans=recursion(n,n,dp);
        return ans ;
    }
};