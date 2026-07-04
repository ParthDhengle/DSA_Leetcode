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
    void rec(TreeNode* node , vector<vector<double>> &map , int level){
        if(!node)return ;
        if(level>=map.size()){
            map.push_back({(double)node->val , 1});
        }else{
            map[level]={map[level][0] + node->val , map[level][1] +1};
        }
        rec(node->left , map , level+1);
        rec(node->right , map, level+1);
    }
    vector<double> averageOfLevels(TreeNode* root) {
        vector<vector<double>> map;
        rec(root,map,0);
        int n=map.size();
        vector<double>ans;

        for(int i=0;i<n;i++){
            ans.push_back((double)map[i][0]/map[i][1]);
        }

        return ans;
    }
};