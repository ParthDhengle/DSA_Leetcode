class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char,string>forward;
        unordered_map<string,char>reverse;

        int n=pattern.size();
        int j=0;
        int m=s.size();
        vector<string>words;
        while(j<m){
            string word="";
            while(j<m and s[j]==' '){
                j++;
            }
            while(j<m and s[j]!=' '){
                word+=s[j];
                j++;
            }
            words.push_back(word);
        }
        if(n!=words.size())return false;
        for(int i=0;i<n;i++){
            char ch=pattern[i];
            string is=words[i];
            
            if(forward.find(ch)==0 and reverse.find(is)==0){
                forward[ch]=is;
                reverse[is]=ch;
            }
            else if(forward[ch]!=is or reverse[is]!=ch){
                return false;
            }
        }
        return true;
    }
};