class Solution {
public:
    string reverseWords(string s) {
        int n=s.size();
        int start=n-1;
        int end=n-1;
        string ans="";
        while(start>=0){
            while(start >= 0 and s[start]==' '){start--;}
            if(start<0)break;
            end=start;
            while(start >=0 and s[start]!=' '){start--;}
            ans+= s.substr(start+1,end-start);
            ans+=' ';
        }
        if(!ans.empty()){ans.pop_back();}
        return ans;
    }
};