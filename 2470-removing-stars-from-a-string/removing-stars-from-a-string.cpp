class Solution {
public:
    string removeStars(string s) {
        int n=s.size();
        string ans="";
        stack<char>st;
        int count=0;
        for(int i=n-1;i>=0;i--){
            char c=s[i];
            if(c=='*'){
                count++;
            }
            else if(count>0){
                count--;
            }else{
                st.push(c);
            }
        }
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        return ans;
    }
};