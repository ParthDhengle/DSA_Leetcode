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
    void dfs(TreeNode* node,int &count, vector<double>arr,int k){
        if(node==NULL)return;
        if(node->val==k){
            count++;
        }
        for(int i=0;i<arr.size();i++){
            arr[i]=arr[i]+node->val;
            if(arr[i]==k){count++;}
        }
        arr.push_back(node->val);
        dfs(node->left,count,arr,k);
        dfs(node->right,count,arr,k);

    }
    int pathSum(TreeNode* root, int targetSum) {
        int count=0;
        vector<double>arr;
        dfs(root,count,arr,targetSum);
        return count;
    }
};