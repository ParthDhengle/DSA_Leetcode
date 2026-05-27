class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans="";
        int n=strs.size();
        for(int i=0;i<strs[0].size();i++){
            char curr=strs[0][i];
            for(int j=1;j<n;j++){
                if(strs[j][i]!=curr){
                    return ans;
                }
            }
            ans+=curr;
        }
        return ans;
    }
};