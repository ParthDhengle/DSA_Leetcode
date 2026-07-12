class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses);

        for(auto i :prerequisites ){
            adj[i[0]].push_back(i[1]);
        }
        vector<int>state(numCourses,0);
        vector<int>ans;

        for(int i=0;i<numCourses;i++){
            if(state[i] ==0 and !dfs(i,adj,state,ans)){
               return {};
            }
        }
        return ans;
    }
    
    bool dfs(int i, vector<vector<int>>&adj , vector<int>& state,vector<int>&ans){
        if(state[i]==1){return false;}
        if(state[i]==2){return true;}
        state[i]=1;

        for(int nei : adj[i]) {
            if(!dfs(nei, adj,state,ans)) return false;
        }
        state[i]=2;
        ans.push_back(i);
        return true;
    }
};