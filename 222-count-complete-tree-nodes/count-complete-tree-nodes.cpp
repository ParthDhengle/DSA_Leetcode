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
    int findLeftHeight(TreeNode* node){
        int height=0;
        while(node){
            height++;
            node=node->left;
        }
        return height;
    }
    int findRightHeight(TreeNode* node){
        int height=0;
        while(node){
            height++;
            node=node->right;
        }
        return height;
    }
    int countNodes(TreeNode* root) {
        if(!root)return 0;
        int l=findLeftHeight(root);
        int r=findRightHeight(root);
        if(l==r)return (1<<l) -1;
        return 1+ countNodes(root->left) + countNodes(root->right);
    }
};