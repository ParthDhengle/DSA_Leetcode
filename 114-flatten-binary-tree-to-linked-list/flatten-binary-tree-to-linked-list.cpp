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
    void flatten(TreeNode* root) {
        stack<TreeNode*>st;
        TreeNode*curr=root;
        while(curr){
            if(curr->left){
                if(curr->right){st.push(curr->right);}
                curr->right=curr->left;
                curr->left=NULL;
            }else if(curr->right==NULL and !st.empty()){
                curr->right=st.top();
                st.pop();
            }
            curr=curr->right;
        }
    }
};