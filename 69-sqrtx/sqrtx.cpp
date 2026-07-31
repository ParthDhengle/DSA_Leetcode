class Solution {
public:
    int mySqrt(int x) {
        if(x==0 or x==1)return x;
        int left=0;
        int right=x;
        while(left<=right){
            int mid=left+(right-left)/2;
            if((long long)mid*mid==(long long)x)return mid;
            else if((long long)mid*mid > x){
                right=mid-1;
            }
            else{
                left=mid+1;
            }
        }
        return right;
    }
};