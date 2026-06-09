class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int>mp;
        if(n==1)return true;
        while(n!=1){
            if(mp.find(n) != mp.end()){return false;}
            mp.insert(n);

            int val=0;
            while(n>0){
                int digit = n%10;
                val+=digit * digit;
                n/=10;
            }
            n=val;
        }
        return true;

    }
};