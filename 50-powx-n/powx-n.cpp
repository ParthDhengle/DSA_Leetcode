class Solution {
public:
    double myPow(double x, int n) {
        int is_neg=false;
        long long N=n;
        if(N<0){
            is_neg=true;
            N=-N;
        }
        if(N==0)return 1;

        double ans=1;

        //simplify and solve exponent;
        while(N){
            if(N%2==0){
                N=N/2;
                x=x*x;
            }else{
                ans*=x;
                N--;
            }
            
        }
        
        //return results;
        if(is_neg){
            ans=1/ans;
        }
        return ans;
    }
};