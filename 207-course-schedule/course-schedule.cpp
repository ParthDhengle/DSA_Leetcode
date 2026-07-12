class Solution {
public:
    bool dfs(int i, vector<vector<int>>&adj , vector<int>& state){
        if(state[i]==1){return false;}
        if(state[i]==2){return true;}
        state[i]=1;

        for(int nei : adj[i]) {
            if(!dfs(nei, adj,state)) return false;
        }
        state[i]=2;
        return true;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses);

        for(auto i :prerequisites ){
            adj[i[0]].push_back(i[1]);
        }
        vector<int>state(numCourses,0);

        for(int i=0;i<numCourses;i++){
            if(state[i] !=2 and !dfs(i,adj,state)){
               return false;
            }
        }
        return true;
    }
};