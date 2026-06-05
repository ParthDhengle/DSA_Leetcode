class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<int>>temp(n,vector<int>(m,0));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int val=0;
                if(i>0){
                    val+=board[i-1][j];
                    if(j>0){
                        val+=board[i-1][j-1];
                    }
                    if(j<m-1){
                        val+=board[i-1][j+1];
                    }
                }
                if(j>0){
                    val+=board[i][j-1];
                }
                if(j<m-1){
                    val+=board[i][j+1];
                }
                if(i<n-1){
                    val+=board[i+1][j];
                    if(j>0){
                        val+=board[i+1][j-1];
                    }
                    if(j<m-1){
                        val+=board[i+1][j+1];
                    }
                }
                temp[i][j]=val;
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==1){
                    if(temp[i][j]<2 || temp[i][j]>3){
                        board[i][j]=0;
                    }
                }else{
                    if(temp[i][j]==3){
                        board[i][j]=1;
                    }
                }
            }
        }

    }
};