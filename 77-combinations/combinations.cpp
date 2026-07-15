class Solution {
public:
void rec(int start, int n,int k,vector<vector<int>>&ans,vector<int>&temp){
    if(k==0){
        ans.push_back(temp);
        return;
    }
    if(start>n)return;
    temp.push_back(start);
    rec(start+1,n,k-1,ans,temp);
    temp.pop_back();
    rec(start+1,n,k,ans,temp);

}
    vector<vector<int>> combine(int n, int k) {
        vector<int>temp;
        vector<vector<int>>ans;
        rec(1,n,k,ans,temp);
        return ans;
    }
};