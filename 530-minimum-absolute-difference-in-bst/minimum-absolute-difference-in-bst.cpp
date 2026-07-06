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
    void rec(TreeNode* node , int &Min , int &prev){
        if(!node)return;
        rec(node->left,Min,prev);
        Min=min( Min ,abs(node->val - prev));
        prev=node->val;
        rec(node->right , Min,prev);
    }
    int getMinimumDifference(TreeNode* root) {
        int Min=100000;
        int prev=100000;

        rec(root,Min,prev);
        return Min;
    }
};