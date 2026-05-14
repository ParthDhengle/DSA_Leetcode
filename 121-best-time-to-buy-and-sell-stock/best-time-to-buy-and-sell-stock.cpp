class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int Min=100000;
        int profit=0;
        for(int i=0;i<n;i++){
            if(prices[i]<Min){Min=prices[i];}
            else{
                profit=max(profit, (prices[i]-Min));
                // cout<<Min<<" "<<prices[i]<<" "<<profit<<endl;
            }
        }
        return profit;
    }
};