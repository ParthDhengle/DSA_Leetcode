class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n=profits.size();
        vector<pair<int,int>>projects(n);
        for(int i=0;i<n;i++){
            projects[i]={capital[i] , profits[i]};
        }
        sort(projects.begin(),projects.end());

        priority_queue<int>max_profit;
        int i=0;
        while(k){
            while(i<n and projects[i].first<=w){
                max_profit.push(projects[i].second);
                i++;
            }
            if(max_profit.empty()){
                break;
            }
            w+=max_profit.top();
            max_profit.pop();
            k--;
        }
        return w;
    }
};