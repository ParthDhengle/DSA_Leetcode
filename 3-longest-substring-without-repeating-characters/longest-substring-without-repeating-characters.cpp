class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int>hash(256,0);
        int n=s.size();
        if(n==1)return 1;
        int i=0;
        int j=0;
        int ans=0;

        while(i<n){
            if(hash[s[i]]==0){
                hash[s[i]]++;
                i++;
                ans=max(ans,i-j);
            }else{
                hash[s[j]]=0;
                j++;
            }

        }
        return ans;
    }
};