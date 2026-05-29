class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n=t.size();
        int m=s.size();
        int i=0;
        int j=0;
        while(i<n and j<m){
            if(s[j]==t[i]){
                j++;
            }
            i++;
        }
        if(j==m){return true;}
        return false;
    }
};