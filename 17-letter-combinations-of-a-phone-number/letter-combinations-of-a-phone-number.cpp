class Solution {
public:
    void combi(string digits, vector<string>&ans, int i,vector<string>hash,string s){
        int n=digits.size();
        if(i==n){
            ans.push_back(s);
            return;
        }
        
        int digit=digits[i]- '0';
        string curr=hash[digit];
        
        for(char c:curr){
            string ns=s+c;
            combi(digits,ans,i+1,hash,ns);
        }
    }
    vector<string> letterCombinations(string digits) {
        int n=digits.size();
        vector<string>hash={"-1","-1","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        vector<string>ans;
        combi(digits,ans,0,hash,"");
        return ans;
    }
};