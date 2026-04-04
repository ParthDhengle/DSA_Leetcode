class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        if(n<3){
            return min(cost[0],cost[1]); 
        }
        int curr=cost[n-3];
        int next1=cost[n-2];
        int next2=cost[n-1];
        for(int i=n-3;i>=0;i--){
            curr=min(next1,next2) + cost[i];
            next2=next1;
            next1=curr;
        }
        return min(next1,next2);
    }
};