class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n=nums.size();
        //normal max:
        int MAX=INT_MIN;
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            if(sum>MAX){
                MAX=sum;
            }
            if(sum<0){
                sum=0;
            }
        }
        if(MAX<0){
            return MAX;
        }
        //circular max:
        int total_sum=0;
        for(int i=0;i<n;i++){
            total_sum+=nums[i];
        }
        int MIN=INT_MIN;
        sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i]*(-1);
            if(sum>MIN){
                MIN=sum;
            }
            if(sum<0){
                sum=0;
            }
        }

        return max(MAX,total_sum -(-MIN));
    }
};