class Solution {
public:
    bool isPalindrome(string s) {
        string ans="";
        int n=s.size();
        for(int i=0;i<n;i++){
            if(isalnum(s[i])){
                ans+=tolower(s[i]);
            }
        }
        string revans=ans;
        reverse(revans.begin(),revans.end());
        return ans==revans;
    }
};