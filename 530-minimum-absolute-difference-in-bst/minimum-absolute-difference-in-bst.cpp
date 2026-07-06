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
void rec(TreeNode* node , vector<int>& arr){
    if(!node)return;
    arr.push_back(node->val);
    rec(node->left,arr);
    rec(node->right,arr);
}
    int getMinimumDifference(TreeNode* root) {
        vector<int>arr;
        rec(root, arr);
        sort(arr.begin() , arr.end());

        int Min=1000000;
        int n=arr.size();
        for(int i=0;i<n-1;i++){
            Min=min(Min , abs(arr[i+1]-arr[i]));
        }
        return Min;
    }
};