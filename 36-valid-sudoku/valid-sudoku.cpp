class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<int>>col(9,vector<int>(9,0));
        vector<vector<int>>row(9,vector<int>(9,0));
        vector<vector<int>>boxes(9,vector<int>(9,0));
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                char curr=board[i][j];
                if(curr=='.'){continue;}
                int val=curr-'0' - 1;
                row[i][val]++;
                col[j][val]++;

                int r=(j/3)+ (i/3) * 3;
                boxes[r][val]++;

                if(row[i][val]>1 or col[j][val]>1 or boxes[r][val]>1){
                    return false;
                }
            }
        }
        return true;

    }
};