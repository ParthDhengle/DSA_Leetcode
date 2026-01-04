class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int ans=0;
        map<vector<int>,int>map;
        int n=grid.size();

        for(int i=0;i<n;i++){
            map[grid[i]]++;
        }
        
        for(int i=0;i<n;i++){
            vector<int>temp;
            for(int j=0;j<n;j++){
                temp.push_back(grid[j][i]);
            }
            if(map[temp]>0){
                ans+=map[temp];
            }
        }
        return ans;
    }
};