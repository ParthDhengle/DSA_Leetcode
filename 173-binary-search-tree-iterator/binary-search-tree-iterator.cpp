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
class BSTIterator {
public:
    queue<int>preOrder;
    void preorder(TreeNode* node, queue<int>& preOrder){
        if(node==NULL)return;
        preorder(node->left,preOrder);
        preOrder.push(node->val);
        preorder(node->right,preOrder);
    }
    BSTIterator(TreeNode* root) {
        preorder(root,preOrder);
    }
    
    int next() {
        if(preOrder.empty())return 0;
        int next=preOrder.front();
        preOrder.pop();
        return next;

    }
    
    bool hasNext() {
        if(!preOrder.empty())return true;
        return false;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */