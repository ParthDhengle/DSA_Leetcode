class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int Max=0;
        int start=0;
        int n=gain.size();
        for(int i=0;i<n;i++){
            start+=gain[i];
            Max=max(Max,start);
        }
        return Max;
    }
};