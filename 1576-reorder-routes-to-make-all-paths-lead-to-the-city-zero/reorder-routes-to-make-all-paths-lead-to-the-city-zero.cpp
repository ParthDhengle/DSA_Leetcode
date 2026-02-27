class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        set<pair<int,int>>conn;
        vector<vector<int>>adjs(n);

        for(int i=0;i<connections.size();i++){
            conn.insert({connections[i][0],connections[i][1]});
            adjs[connections[i][0]].push_back(connections[i][1]);
            adjs[connections[i][1]].push_back(connections[i][0]);
        }
        stack<int>st;
        st.push(0);
        vector<bool>visited(n,false);
        int count=0;
        visited[0]=true;
        while(!st.empty()){
            int curr=st.top();
            st.pop();
            for(auto n:adjs[curr]){
                if(!visited[n]){
                    visited[n]=true;
                    st.push(n);
                    if(conn.find({n,curr})==conn.end()){
                        count++;
                    }
                }
            }
        }
        return count;
    }
};