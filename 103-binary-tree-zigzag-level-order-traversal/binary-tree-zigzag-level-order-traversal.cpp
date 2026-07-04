/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
 void rec(TreeNode* node , vector<vector<int>> &map , int level){
        if(!node)return ;
        if(level>=map.size()){
            map.push_back({node->val});
        }else{
            map[level].push_back(node->val);
        }
        rec(node->left , map , level+1);
        rec(node->right , map, level+1);
    }
    
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> map;
        rec(root,map,0);
        int flag=0;
        int n=map.size();

        for(int i=0;i<n;i++){
            if(flag==1){
                flag=0;
                reverse(map[i].begin(),map[i].end());
            }else{
                flag=1;
            }
        }
        return map;
    }
};