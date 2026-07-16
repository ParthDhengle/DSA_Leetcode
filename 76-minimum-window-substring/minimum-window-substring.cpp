class Solution {
public:
    string minWindow(string s, string t) {
        string ans=s;
        vector<int>hash(256,0);
        int c=t.size();

        for(char i : t){
            hash[i]++;
        }

        int l=0,r=0;
        int n=s.size();
        int len=INT_MAX;
        int start=0;
        
        while (r<n){
            if(hash[s[r]] >0){
                c--;
            }
            hash[s[r]]--;
            while(c==0){
                if(r-l+1<len){
                    len=r-l+1;
                    start=l;
                }
                hash[s[l]]++;
                if (hash[s[l]] > 0){
                    c++;
                }
                l++;
            }
            r++;
        }
        if(len==INT_MAX)return "";
        return s.substr(start,len);
    }
};