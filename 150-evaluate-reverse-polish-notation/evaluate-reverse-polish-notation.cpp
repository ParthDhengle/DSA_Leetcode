class Solution {
public:
    int cal(int val1,int val2,string op){
        if(op=="+")return val1+val2;
        if(op=="-")return val1-val2;
        if(op=="*")return val1*val2;
        return val1/val2;
    }
    int evalRPN(vector<string>& tokens) {
        stack<int>st;
        for(auto i:tokens){
            if(i=="+" or i=="-" or i=="*" or i=="/"){
                int val2=st.top();
                st.pop();
                int val1=st.top();
                st.pop();

                st.push(cal(val1,val2,i));
            }else{
                st.push(stoi(i));
            }
            
        }
        return st.top();
    }
};