class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();

        vector<vector<int>>ans;
        for(int i=0;i<n;i++){
            if(i>0 and nums[i]==nums[i-1]){continue;}
            int l=i+1;
            int h=n-1;
            while(l<h){
                int sum=nums[i]+nums[l]+nums[h];
                if(sum==0){
                    ans.push_back({nums[i],nums[l],nums[h]});
                    l++;
                    h--;
                    while(l<n and nums[l]==nums[l-1]){
                        l++;
                    }
                    while(h>0 and nums[h]==nums[h+1]){
                        h--;
                    }
                }
                else if(sum>0){
                    h--;
                }else{l++;}
            }
        }
        return ans;
    }
};