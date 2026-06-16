class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        if(s.size()%2!=0){return false;}
        for(auto i : s){
            if(i=='(' or i=='{' or i=='['){
                st.push(i);
            }else if(st.empty()){return false;}
            else{
                char cur=st.top();
                st.pop();
                if((cur=='(' and i!=')') or (cur=='{' and i!='}') or (cur=='[' and i!=']')){
                    return false;
                }
            }
        }
        if(!st.empty()){return false;}
        return true;
    }
};