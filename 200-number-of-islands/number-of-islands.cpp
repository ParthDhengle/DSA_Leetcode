class Solution {
public:
    void cover(vector<vector<char>>&grid , vector<vector<int>>&visited , int i, int j){
        queue<pair<int,int>>q;
        q.push({i,j});
        visited[i][j]=1;
        while(!q.empty()){
            i=q.front().first;
            j=q.front().second;
            q.pop();
            if(i-1>=0 and grid[i-1][j]=='1' and !visited[i-1][j]){q.push({i-1,j});visited[i-1][j]=1;}
            if(i+1<grid.size() and grid[i+1][j]=='1' and !visited[i+1][j]){q.push({i+1,j});visited[i+1][j]=1;}
            if(j-1>=0 and grid[i][j-1]=='1' and !visited[i][j-1]){q.push({i,j-1});visited[i][j-1]=1;}
            if(j+1<grid[0].size() and grid[i][j+1]=='1' and !visited[i][j+1]){q.push({i,j+1});visited[i][j+1]=1;}
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>visited(n,vector<int>(m,0));

        int island=0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1' and !visited[i][j]){
                    island++;
                    cover(grid,visited,i,j);
                }
            }
        }
        return island;
    }
};