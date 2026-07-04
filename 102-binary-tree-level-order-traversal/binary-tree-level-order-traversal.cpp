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
    
    vector<vector<int>> levelOrder(TreeNode* root) {
         vector<vector<int>> ans;
        rec(root,ans,0);
        return ans;
    }
};