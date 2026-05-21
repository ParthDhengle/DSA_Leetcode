class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int total=0;
        int temp=0;
        int start=0;
        int n=gas.size();
        for(int i=0;i<n;i++){
            int diff=gas[i]-cost[i];
            total+=diff;
            temp+=diff;
            if(temp<0){
                start=i+1;
                temp=0;
            }
        }
        return total>=0?start:-1;
    }
};