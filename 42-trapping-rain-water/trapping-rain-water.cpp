class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int>Lm(n,0);
        vector<int>Rm(n,0);
        vector<int>ans(n,0);
        int j=n-2;
        for(int i=1;i<n;i++){
            Lm[i]=max(Lm[i-1],height[i-1]);
            Rm[j]=max(Rm[j+1],height[j+1]);
            j--;
        }
        int trap=0;
        for(int i=0;i<n;i++){
            trap+=max(min(Lm[i] , Rm[i])-height[i] , 0);
        }
        return trap;
    }
};