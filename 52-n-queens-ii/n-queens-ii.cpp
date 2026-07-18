class Solution {
public:
    void rec(int n, int i, int&ans, vector<bool>&col, vector<bool>&d1, vector<bool>&d2){
        if(i==n){
            ans++;
            return;
        }

        for(int j=0;j<n;j++){
            if(col[j] or d1[i-j+n-1] or d2[i+j]){continue;}
            col[j]=true;
            d1[i-j+n-1]=true;
            d2[i+j]=true;
            rec(n,i+1,ans,col,d1,d2);
            col[j]=false;
            d1[i-j+n-1]=false;
            d2[i+j]=false;
        }
    }
    int totalNQueens(int n) {
        vector<bool>col(n,false);
        vector<bool>d1(n*2 -1 , false);
        vector<bool>d2(n*2 -1,false);
        int ans=0;
        rec(n, 0, ans, col,d1,d2);
        return ans;
    }
};