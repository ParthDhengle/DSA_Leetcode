class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry=0;
        int n=digits.size();
        for(int i=n-1;i>=0;i--){
            int sum=carry+digits[i];
            if(i==n-1){sum+=1;}
            if(sum>9){
                carry=1;
                digits[i]=sum%10;
            }else{
                carry=0;
                digits[i]=sum;
            }
        }
        if(carry){
            vector<int>temp={1};
            temp.insert(temp.end(),digits.begin(),digits.end());
            digits=temp;
        }
        return digits;
    }
};