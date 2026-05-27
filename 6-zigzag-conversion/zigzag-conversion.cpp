class Solution {
public:
    string convert(string s, int numRows) {
        int n=s.size();
        if(numRows<=1)return s;
        vector<string>arr(numRows,"");
        int j=0;
        int dir=-1;
        for(int i=0;i<n;i++){
            if(j==numRows-1 || j== 0)dir*=-1;
            arr[j]+=s[i];
            if(dir==1)j++;
            else j--;
        }
        string ans="";
        for(auto i: arr){
            ans+=i;
        }
        return ans;
    }
};