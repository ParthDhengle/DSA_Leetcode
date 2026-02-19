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
    void dfs(TreeNode* node, vector<int>& arr){
        if(node==NULL)return;
        if(node->left==NULL and node->right==NULL){
            arr.push_back(node->val);
            return;
        }
        dfs(node->left,arr);
        dfs(node->right,arr);
        return;
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int>v1;
        vector<int>v2;

        dfs(root1,v1);
        dfs(root2,v2);
        return v1==v2;
    }
};