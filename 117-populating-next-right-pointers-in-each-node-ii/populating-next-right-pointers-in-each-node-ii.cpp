/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(root==NULL)return NULL;
        queue<Node*>q;
        q.push(root);
        int counter1=1;
        int counter2=0;
        while(!q.empty()){
            Node*curr=q.front();
            q.pop();
            if(curr->left){
                q.push(curr->left);
                counter2++;
            }
            if(curr->right){
                q.push(curr->right);
                counter2++;
            }

            if(counter1<=1){
                curr->next=NULL;
                counter1=counter2;
                counter2=0;
            }else{
                curr->next=q.front();
                counter1--;
            }
        }
        return root;
    }
};