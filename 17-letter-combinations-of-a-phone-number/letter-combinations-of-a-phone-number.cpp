class Solution {
public:
    void back_track(int k, string &ele, string &digits,vector<string>&number, vector<string>&ans,int n){
        if(k==n){
            ans.push_back(ele);
            return;
        }
        int curr=digits[k]-'2';
        for(int i=0;i<number[curr].size();i++){
            ele+=number[curr][i];
            k++;
            back_track(k,ele,digits,number,ans,n);
            k--;
            ele.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> number = {"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

        int n=digits.size();

        vector<string>ans;
        string ele="";

        back_track(0,ele,digits,number,ans,n);
        return ans;
    }
};