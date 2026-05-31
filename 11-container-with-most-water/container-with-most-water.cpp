class Solution {
public:
    int maxArea(vector<int>& height) {
        int Max=0;
        int l=0;
        int n=height.size();
        int h=n-1;
        while(l<=h){
            int boundaryHeight=min(height[l],height[h]);
            Max=max(Max, boundaryHeight*(h-l));
            if(height[l]<height[h]){
                l++;
            }else{h--;}
        }
        return Max;
    }
};