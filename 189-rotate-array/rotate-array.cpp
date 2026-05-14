class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        k=k%n;
        if(k==0)return;
        vector<int>temp(nums.begin()+(n-k),nums.end());
        for(int i=n-1;i>=0+k;i--){
            nums[i]=nums[i-k];
        }
        for(int i=0;i<k;i++){
            nums[i]=temp[i];
        }
    }
};