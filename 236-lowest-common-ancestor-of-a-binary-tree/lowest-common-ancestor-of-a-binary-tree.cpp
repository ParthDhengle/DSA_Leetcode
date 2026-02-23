/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* node, TreeNode* p, TreeNode* q) {
        if(node==NULL or node==p or node==q){
            return node;
        }
        TreeNode* left=lowestCommonAncestor(node->left,p,q);
        TreeNode* right=lowestCommonAncestor(node->right,p,q);
        if(left==NULL){
            return right;
        }
        else if(right==NULL){return left;}
        else{return node;}
        return NULL;
    }
};