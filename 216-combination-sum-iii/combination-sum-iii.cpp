class Solution {
public:
    void back_track(vector<vector<int>>&ans,vector<int>curr,int k,int n,int x,int sum){
        
        if(curr.size()==k){
            if(sum==n){
                ans.push_back(curr);
            }
            return;
        }
        for(int j=x;j<=9;j++){
            if(sum+j>n){break;}
            curr.push_back(j);
            back_track(ans,curr,k,n,j+1,sum+j);
            curr.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int>curr;
        back_track(ans,curr,k,n,1,0);
        return ans;
    }
};