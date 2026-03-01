class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int n=maze.size();
        int m=maze[0].size();
        int x=entrance[0];
        int y=entrance[1];
        queue<pair<int,int>>q;
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        q.push({x,y});
        visited[x][y]=true;

        int step=0;
        vector<pair<int,int>>dir={{-1,0},{1,0},{0,-1},{0,1}};

        while(!q.empty()){
            int size=q.size();
            step++;
            while(size--){
                auto [x,y]=q.front();
                q.pop();
                for(auto [dx,dy]:dir){
                    int newx=x+dx;
                    int newy=y+dy;
                    if(newx>=0 and newx<n and newy>=0 and newy<m and maze[newx][newy]=='.' and !visited[newx][newy]){
                        if(newx==0 or newx==n-1 or newy==0 or newy==m-1){
                            return step;
                        }
                        visited[newx][newy]=true;
                        q.push({newx,newy});

                    }
                }
            }
        }
        return -1;
    }
};