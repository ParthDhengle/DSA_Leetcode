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
    TreeNode* create(TreeNode * node, vector<int>& inorder, vector<int>& postorder){
        int in=inorder.size();
        int po=postorder.size();
        int idx=0;
        for(int i=0;i<in;i++){
            if(inorder[i]==node->val){
                idx=i;
                break;
            }
        }
        vector<int>left_inorder(inorder.begin(),inorder.begin()+idx);
        int left_inorder_size=left_inorder.size();
        vector<int>right_inorder(inorder.begin()+idx+1,inorder.end());
        vector<int>left_postorder(postorder.begin(), postorder.begin()+left_inorder_size);
        vector<int>right_postorder(postorder.begin()+left_inorder_size,postorder.end()-1);

        if(!left_postorder.empty()){
            node->left=create(new TreeNode(left_postorder.back()) , left_inorder, left_postorder);
        }else{
            node->left=NULL;
        }
        if(!right_postorder.empty()){
            node->right=create(new TreeNode(right_postorder.back()) , right_inorder , right_postorder) ; 
        }else{
            node->right=NULL;
        }
        return node;

    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return create(new TreeNode(postorder.back()) , inorder,postorder);
    }
};