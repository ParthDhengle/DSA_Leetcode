class Solution {
public:
    bool isIsomorphic(string s, string t) {
        vector<int>hash(127,0);
        vector<int>hash2(127,0);

        int n=s.size();
        if(n!=t.size())return false;
        for(int i=0;i<n;i++){
            int is=(int)s[i];
            int it=(int)t[i];
            if(hash[is]==0 and hash2[it]==0){
                hash[is]=it;
                hash2[it]=is;
            }else if(hash[is]!=it or hash2[it]!=is){
                return false;
            }else{
                continue;
            }
        }
        return true;
    }
};