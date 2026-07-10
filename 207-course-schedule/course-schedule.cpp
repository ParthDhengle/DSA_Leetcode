class Solution {
public:
    bool rec(int i, unordered_map<int,vector<int>>&mp , unordered_set<int> visited , unordered_set<int>&mem){
        if(visited.find(i)!=visited.end()){return false;}
        if(mem.find(i)!=mem.end())return true;
        visited.insert(i);
        if(mp.find(i) != mp.end()){
            for(int nei : mp[i]) {
                if(!rec(nei, mp, visited, mem)) return false;
            }
        }
        mem.insert(i);
        return true;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,vector<int>>mp;
        int n=prerequisites.size();
        for(auto i :prerequisites ){
            mp[i[0]].push_back(i[1]);
        }
        //if reachable add to mem; 
        unordered_set<int>mem;

        for(int i=0;i<n;i++){
            int curr=prerequisites[i][0];

            unordered_set<int>visited;
            if(mem.find(curr)==mem.end() and !rec(curr, mp, visited, mem))return false;
            mem.insert(curr);
        }
        return true;
    }
};