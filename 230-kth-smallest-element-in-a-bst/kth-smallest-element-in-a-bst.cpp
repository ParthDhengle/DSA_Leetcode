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
    int rec(TreeNode* node, int k, int& counter, int& ans){
        if(!node)return -1;
        
        
        rec(node->left,k,counter, ans);
        counter++;
        if(k==counter){
            ans=node->val;
            return ans;
        }
        rec(node->right,k,counter,ans);
        return ans;
    }
    int kthSmallest(TreeNode* root, int k) {
        int ans=-1;
        int counter=0;
        return rec(root , k,counter,ans);
    }
};