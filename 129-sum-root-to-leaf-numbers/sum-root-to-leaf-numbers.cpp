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
    int S(TreeNode* node, int digit){
        if(!node)return 0;
        digit=digit*10 + node->val;

        if(node->left==NULL and node->right==NULL){
            return digit;
        }
        return S(node->left,digit) + S(node->right,digit);
    }
    int sumNumbers(TreeNode* root) {
        return S(root,0);
    }
};