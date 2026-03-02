class Solution {
public:
bool is_reachable(vector<vector<int>>& grid,int x,int y){
    if(x!=0 and grid[x-1][y]==0){return false;}
    if(x!=grid.size()-1 and grid[x+1][y]==0)return false;
    if(y!=0 and grid[x][y-1]==0)return false;
    if(y!=grid[0].size() and grid[x][y+1]==0)return false;
    return true;
}
    int orangesRotting(vector<vector<int>>& grid) {
        int minutes=0;
        queue<pair<int,int>>q;
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }
            }
        }
        vector<pair<int,int>>dir={{-1,0},{1,0},{0,-1},{0,1}};
        vector<vector<int>>visited(n,vector<int>(m,false));
        while(!q.empty()){
            int size=q.size();
            while(size--){
                auto [x,y]=q.front();
                q.pop();
                for(auto[dx,dy]:dir){
                    int nx=x+dx;
                    int ny=y+dy;
                    if(nx>=0 and nx<n and ny>=0 and ny<m and grid[nx][ny]==1 and !visited[nx][ny]){
                        visited[nx][ny]=true;
                        grid[nx][ny]=2;
                        q.push({nx,ny});
                    }
                }
            }
            if(q.size()>0){minutes++;}
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    return -1;
                }
            }
        }
        
        return minutes;
    }
};