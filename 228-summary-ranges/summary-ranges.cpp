class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string>ans;
        int n=nums.size();
        if(n==0){return {};}
        if(n==1){
            return {to_string(nums[0])};
        }
        int start=0;
        int end=0;
        for(int i=0;i<n;i++){
            if(i==n-1 or nums[i]+1 != nums[i+1]){
                
                if(start==end){
                    ans.push_back(to_string(nums[start]));
                }else{
                    ans.push_back(to_string(nums[start])+"->"+to_string(nums[end]));
                }
                start=end+1;
                end++;
            }
            else{
                end++;
            }
        }
        return ans;
    }
};