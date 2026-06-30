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
    TreeNode* create(TreeNode*node , vector<int>& preorder, vector<int>& inorder){
        if(preorder.empty())return NULL;
        if(preorder.size()<=1)return node;
        int idx=0;
        for(int i=0;i<inorder.size();i++){
            if(inorder[i]==preorder[0]){
                idx=i;
            }
        }
        vector<int>left_inorder(inorder.begin(),inorder.begin()+idx);
        int left_inorder_size=left_inorder.size();
        vector<int>right_inorder(inorder.begin()+idx+1,inorder.end());
        vector<int>left_preorder(preorder.begin()+1, preorder.begin()+1+left_inorder_size);
        vector<int>right_preorder(preorder.begin()+1+left_inorder_size,preorder.end());

        if (!left_preorder.empty())
            node->left = create(new TreeNode(left_preorder[0]),
                                left_preorder,
                                left_inorder);
        else
            node->left = NULL;

        if (!right_preorder.empty())
            node->right = create(new TreeNode(right_preorder[0]),
                                right_preorder,
                                right_inorder);
        else
            node->right = NULL;

        return node;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return create(new TreeNode(preorder[0]) , preorder, inorder);
    }
};