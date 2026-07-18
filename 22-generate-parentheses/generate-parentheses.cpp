class Solution {
public:
    void rec(int n,int i,vector<string>& ans, string curr,int open){
        if(curr.size()==n*2){
            ans.push_back(curr);
            return;
        }
        if(i<n){
            rec(n,i+1,ans,curr+'(',open+1);
        }
        if(open>0){
            rec(n,i,ans,curr+')',open-1);
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        rec(n,0,ans,"",0);
        return ans;
    }
};