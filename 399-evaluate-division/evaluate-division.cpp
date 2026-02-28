class Solution {
public:
 double DFS(string src,string dst,unordered_map<string,vector<pair<string,double>>>&adjs, unordered_set<string>&visited){
    if(adjs.find(src)==adjs.end() or adjs.find(dst)==adjs.end()){
        return -1;
    }
    if(src==dst){
        return 1;
    }
    visited.insert(src);
    for(auto n:adjs[src]){
        if(visited.find(n.first)!=visited.end()){
            continue;
        }
        double res=DFS(n.first,dst,adjs,visited);
        if(res!=-1){
            return res*n.second;
        }
    }
    return -1;
 }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int n=equations.size();
        unordered_map<string,vector<pair<string,double>>> adjs;
        for(int i=0;i<n;i++){
            string a=equations[i][0];
            string b=equations[i][1];
            double v=values[i];
            adjs[a].push_back({b,v});
            adjs[b].push_back({a,1/v});
        }
        vector<double>result;
        for(auto query:queries){
            unordered_set<string>visited;
            result.push_back(DFS(query[0],query[1],adjs,visited));
        }
        return result;
    }
};