class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int total=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            total+=nums[i];
        }
        int prefix=0;
        int suffix=total;
        for(int i=0;i<n;i++){
            if(prefix==suffix-nums[i]){
                return i;
            }
            prefix+=nums[i];
            suffix=total-prefix;
        }
        return -1;
    }
};