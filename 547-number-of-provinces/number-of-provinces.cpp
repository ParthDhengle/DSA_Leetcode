class Solution {
public:
    void dfs(int node,vector<bool>&vis,vector<vector<int>>adjs){
        
        queue<int>q;
        q.push(node);
        while(!q.empty()){
            int curr=q.front();
            vis[curr]=true;
            q.pop();
            int n=adjs[curr].size();
            for(int n:adjs[curr]){
                if(!vis[n]){
                    vis[n]=true;
                    q.push(n);
                }
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<vector<int>>adjs(n+1);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j]==1 and i!=j){
                    adjs[i].push_back(j);
                    adjs[j].push_back(i);
                }
            }
        }

        int count=0;
        vector<bool>vis(n,0);

        for(int i=0;i<n;i++){
            if(!vis[i]){
                count++;
                dfs(i,vis,adjs);
            }
        }
        return count;
    }
};