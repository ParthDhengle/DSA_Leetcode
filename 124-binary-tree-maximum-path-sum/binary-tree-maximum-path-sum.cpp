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
    int sum(TreeNode* node, int & Max){
        if(!node)return 0;
        int left=max(0,sum(node->left,Max));
        int right=max(0,sum(node->right,Max));
        
        Max=max(Max,node->val + left+right);
        return node->val + max(left,right);
    }
    int maxPathSum(TreeNode* root) {
        int Max=-100000;
        sum(root,Max);
        return Max;
    }
};