class Solution {
public:
    vector<int> asteroidCollision(vector<int>& arr) {
        int n=arr.size();
        vector<int>st;
        for(int a:arr){
            bool distroyed=false;
            while(!st.empty() and a<0 and st.back()>0){
                if(st.back()< abs(a)){
                    st.pop_back();
                }
                else if(st.back()==abs(a)){
                    st.pop_back();
                    distroyed=true;
                    break;
                }
                else{
                    distroyed=true;
                    break;
                }
            }
            if(!distroyed){
                st.push_back(a);
            }
        }
        return st;
    }
};