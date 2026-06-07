class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int>hasht(127,0);
        vector<int>hashs(127,0);
        
        int n=s.size();
        if(n!=t.size())return false;

        for(int i=0;i<n;i++){
            hashs[(int)s[i]]++;
            hasht[(int)t[i]]++;
        }
        for(int i=0;i<127;i++){
            if(hasht[i]!=hashs[i]){
                return false;
            }
        }
        return true;
    }
};