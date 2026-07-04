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
    void recur(TreeNode* node ,vector<int> & ans,int & height,int curr ){
        if(!node)return;
        if(curr>=height){
            ans.push_back(node->val);
            height++;
        }
        recur(node->right, ans,height,curr+1);
        recur(node->left,ans,height,curr+1);

    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int>ans;
        int height=0;
        recur(root,ans,height,0);
        return ans;
    }
};