class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int m=matrix[0].size();

        int l=0;
        int h=n*m -1;
        while(l<=h){
            int mid=l+(h-l)/2;
            int row=mid/m;
            int col=mid%m;
            int curr=matrix[row][col];

            if(target==curr){
                return true;
            }else if(curr < target){
                l=mid+1;
            }else{
                h=mid-1;
            }
        }
        return false;
    }
};