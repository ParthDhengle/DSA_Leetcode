/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
Node* dfs(Node* node, unordered_map<Node*,Node*>&mp){
    vector<Node*>neigh;
    Node* clone=new Node(node->val);
    mp[node]=clone;
    for(auto i:node->neighbors){
        if(mp.find(i)!=mp.end()){
            neigh.push_back(mp[i]);
        }else{
            neigh.push_back(dfs(i,mp));
        }
    }
    clone->neighbors=neigh;
    return clone;
}
    Node* cloneGraph(Node* node) {
        if(!node)return NULL;
        if(node->neighbors.size()==0){return new Node(node->val);}
        unordered_map<Node*,Node*>mp;
        return dfs(node,mp);
    }
};