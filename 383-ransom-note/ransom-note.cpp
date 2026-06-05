class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int>hash(27,0);
        int n=magazine.size();
        int m=ransomNote.size();
        for(int i=0;i<n;i++){
            hash[magazine[i]-'a']++;
        }
        for(int i=0;i<m;i++){
            if(hash[ransomNote[i]-'a'] <=0){
                return false;
            }
            hash[ransomNote[i]-'a']--;
        }
        return true;
    }
};