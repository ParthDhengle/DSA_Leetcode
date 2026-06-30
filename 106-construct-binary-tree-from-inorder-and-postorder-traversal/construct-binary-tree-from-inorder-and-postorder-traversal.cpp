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
TreeNode* tree(vector<int>& inorder, vector<int>& postorder, int& index,unordered_map<int,int>&mp , int start,int end ){
    if(start>end or index<0)return NULL;
    TreeNode* tn=new TreeNode(postorder[index]);

    int inorder_idx=mp[postorder[index]];
    index--;

    tn->right=tree(inorder, postorder,index,mp, inorder_idx+1,end);
    tn->left=tree(inorder,postorder, index, mp, start,inorder_idx-1);

    return tn;
}
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int>mp;
        int n=inorder.size();
        for(int i=0;i<n;i++){
            mp[inorder[i]] =  i;
        }
        int index=n-1;
        return tree(inorder,postorder,index,mp,0,n-1);
    }
};