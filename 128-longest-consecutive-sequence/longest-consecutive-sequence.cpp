class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>st;
        for(int num:nums){
            st.insert(num);
        }
        int maxLen=0;
        for(auto i:st){
            if(st.find(i-1)==st.end()){
                int curr=i;
                int currLen=1;
                while(st.find(curr+1)!=st.end()){
                    currLen++;
                    curr++;
                }
                maxLen=max(maxLen,currLen);
            }
        }
        return maxLen;
    }
};