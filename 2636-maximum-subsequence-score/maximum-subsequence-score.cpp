class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int n=nums1.size();
        vector<pair<int,int>>track(n);

        for(int i=0;i<n;i++){
            track[i]={nums2[i],nums1[i]};
        }
        sort(track.rbegin(),track.rend());

        long long ans=-100000;
        long long sum=0;
        priority_queue<int,vector<int>,greater<int>>pq;

        for(int i=0;i<n;i++){
            int x=track[i].first;
            int y=track[i].second;
            pq.push(y);
            sum+=y;
            if(pq.size()>k){
                sum-=pq.top();
                pq.pop();
            }
            if(pq.size()==k){
                ans=max(ans, sum*x);
            }
        }
        return ans;
    }
};