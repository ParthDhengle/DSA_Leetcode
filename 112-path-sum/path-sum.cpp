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

    bool rec(TreeNode* node, int targetSum, int curr_sum){
        if(!node)return false;
        curr_sum+=node->val;
        if(node->left==NULL and node->right==NULL){
            if(curr_sum==targetSum)return true;
            return false;
        }
        return (rec(node->left , targetSum, curr_sum) or rec(node->right , targetSum, curr_sum));
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        return rec(root,targetSum , 0);
    }
};