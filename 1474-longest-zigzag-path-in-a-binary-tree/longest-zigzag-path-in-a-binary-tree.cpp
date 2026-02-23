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
    void zigzag(TreeNode* node, int dir,int &Max,int &count){
        if(node==NULL)return;
        count++;
        Max=max(Max,count);
        
        if(dir==0){
            zigzag(node->right,1,Max,count);
            count=0;
            zigzag(node->left,0,Max,count);
        }else{
            zigzag(node->left,0,Max,count);
            count=0;
            zigzag(node->right,1,Max,count);
        }
    }
    int longestZigZag(TreeNode* root) {
        int count=0;
        int Max=0;
        zigzag(root->right,1,Max,count);
        count=0;
        zigzag(root->left,0,Max,count);
        return Max;
    }
};