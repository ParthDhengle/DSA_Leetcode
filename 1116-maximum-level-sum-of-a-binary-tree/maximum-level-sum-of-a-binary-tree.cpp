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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*>q;
        int Max=-100000;
        int res_lev=0;
        int curr_lev=1;
        q.push(root);
        while(!q.empty()){
            int sum=0;
            int n=q.size();
            while(n--){
                TreeNode* curr_node=q.front();
                q.pop();
                sum+= curr_node->val;
                if(curr_node->left){
                    q.push(curr_node->left);
                }
                if(curr_node->right){
                    q.push(curr_node->right);
                }
            }
            if(Max<sum){
                Max=sum;
                res_lev=curr_lev;
            }
            curr_lev++;
        }
        return res_lev;
    }
};