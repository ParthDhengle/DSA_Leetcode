class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<vector<int>>dir={{0,1},{1,0},{0,-1},{-1,0}};
        int n=matrix.size();
        int m=matrix[0].size();
        int k=0;
        vector<int>ans(m*n);
        vector<vector<int>>visited(n,vector<int>(m,0));

        int i=0;
        int j=0;
        int l=0;
        while(k<m*n){
            cout<<"i : "<<i<<" j : "<<j<<endl;
            if(visited[i][j]!=0){return ans;}
            ans[k]=matrix[i][j];
            k++;
            visited[i][j]++;
            int ti=i+dir[l][0];
            int tj=j+dir[l][1];
            if(ti<0 || tj<0 || tj>=m || ti>=n || visited[ti][tj]!=0){
                l++;
                if(l>=4){l=0;}
            }
            i+=dir[l][0];
            j+=dir[l][1];
        }
        return ans;
    }
};