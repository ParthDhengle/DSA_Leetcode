/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    bool is_leaf(vector<vector<int>>&grid, int x,int y,int size){
        int val=grid[x][y];
        for(int i=x;i<x+size;i++){
            for(int j=y;j<y+size;j++){
                if(grid[i][j]!=val){
                    return false;
                }
            }
        }
        return true;
    }

    Node* exp(vector<vector<int>>& grid, int x,int y, int size){
        if(is_leaf(grid,x,y,size)){
            return new Node(grid[x][y],true);
        }
        Node* node=new Node();

        int half=size/2;

        Node* tl=exp(grid,x,y,size/2);

        Node* tr=exp(grid,x,y+half,size/2);

        Node* bl=exp(grid,x+half,y,size/2);
        
        Node* br=exp(grid,x+half,y+half,size/2);
        
        node->isLeaf=false;
        node->val=grid[x][y];
        node->topLeft=tl;
        node->topRight=tr;
        node->bottomLeft=bl;
        node->bottomRight=br;
        return node;
    }
    Node* construct(vector<vector<int>>& grid) {
        int n=grid.size();
        if(n==1)return new Node(grid[0][0],true);
        
        return exp(grid,0,0,n);
        
    }
};