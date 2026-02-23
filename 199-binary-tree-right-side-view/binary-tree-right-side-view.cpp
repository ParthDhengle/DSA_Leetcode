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
    void right_dfs(TreeNode* node,vector<int>&ans,int pos){
        if(node==NULL)return;
        if(pos==ans.size()){ans.push_back(node->val);}
        
        right_dfs(node->right,ans,pos+1);
        right_dfs(node->left,ans,pos+1);

    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int>ans;
        right_dfs(root,ans,0);
        return ans;
    }
};