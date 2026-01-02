class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int zero=0;
        int n=nums.size();
        int left=0;
        int right=0;
        int Max=0;
        while(right<n){
            if(nums[right]==0){zero++;}
            if(zero>1){
                if(nums[left]==0){
                    zero--;
                }
                left++;
            }
            Max=max(Max, right-left);
            right++;
        }
        if (Max==n){return Max-1;}
        return Max;
    }
};