class Solution {
public:
    bool rec(vector<vector<char>>& board,vector<vector<bool>>&visited, string word, int idx,int i,int j){
        int n=board.size();
        int m=board[0].size();
        if(idx==word.size()){
            return true;
        }
        visited[i][j]=true;
        bool found=false;

        if(i>0 and !visited[i-1][j] and board[i-1][j]==word[idx]){
            found=rec(board,visited,word,idx+1,i-1,j);
        }
        if(!found and i<n-1 and !visited[i+1][j] and board[i+1][j]==word[idx]){
            found=rec(board,visited,word,idx+1,i+1,j);
        }
        if(!found and j>0 and !visited[i][j-1] and board[i][j-1]==word[idx]){
            found=rec(board,visited,word,idx+1,i,j-1);
        }
        if(!found and j<m-1 and !visited[i][j+1] and board[i][j+1]==word[idx]){
            found=rec(board,visited,word,idx+1,i,j+1);
        }
        visited[i][j]=false;
        return found;
        
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<bool>>visited(n,vector<bool>(m,false));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==word[0] and rec(board,visited,word,1,i,j)){
                    return true;
                }
            }
        }
        return false;
    }
};