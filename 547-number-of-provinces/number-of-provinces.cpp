class Solution {
public:
    void dfs(int node, vector<bool>& vis, vector<vector<int>>& isConnected) {
        vis[node] = true;

        for(int j = 0; j < isConnected.size(); j++) {
            if(isConnected[node][j] == 1 && !vis[j]) {
                dfs(j, vis, isConnected);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        // vector<vector<int>>adjs(n+1);
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<n;j++){
        //         if(isConnected[i][j]==1 and i!=j){
        //             adjs[i].push_back(j);
        //             adjs[j].push_back(i);
        //         }
        //     }
        // }

        int count=0;
        vector<bool>vis(n,0);

        for(int i=0;i<n;i++){
            if(!vis[i]){
                count++;
                dfs(i,vis,isConnected);
            }
        }
        return count;
    }
};