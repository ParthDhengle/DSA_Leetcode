class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        queue<int>q;
        q.push(0);
        vector<bool>visited(n,false);

        while(!q.empty()){
            int key=q.front();
            q.pop();
            if(!visited[key]){
                int m=rooms[key].size();
                visited[key]=true;
                for(int k:rooms[key]){
                    if(!visited[k]){
                        q.push(k);
                    }
                }
            }
        }

        for(bool i:visited){
            if(!i){
                return false;
            }
        }
        return true;
    }
};