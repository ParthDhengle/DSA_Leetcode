class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=0;
        int j=1;
        int flag=0;
        while(j<nums.size()){
            if(nums[i]==nums[j]){
                if(flag==0){
                    i++;
                    nums[i]=nums[j];
                    flag=1;
                }
                j++;
            }
            else{
                i++;
                nums[i]=nums[j];
                j++;
                flag=0;
            }
        }
        return i+1;
    }
};