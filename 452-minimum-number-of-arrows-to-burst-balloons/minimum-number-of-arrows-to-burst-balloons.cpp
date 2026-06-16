class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int n=points.size();
        if(n==0){return 0;}
        sort(points.begin(),points.end());
        int ans=1;
        int num=points[0][1];
        for(auto i:points){
            cout<<"["<<i[0]<<" , "<<i[1]<<"] , ";
        }

        for(int i=1;i<n;i++){
            if(points[i][0] > num){
                ans++;
                num=points[i][1];
            }else{
                num=min(num,points[i][1]);
            }
        }
        return ans;
    }
};