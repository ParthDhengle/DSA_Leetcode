/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int pairSum(ListNode* head) {
        stack<ListNode*>st;
        ListNode* x=head;
        ListNode* y=head;
        while(y!=NULL){
            st.push(x);
            x=x->next;
            y=y->next->next;
        }
        int ans=0;
        while(!st.empty()){
            ans=max(ans,x->val + st.top()->val);
            st.pop();
            x=x->next;
        }
        return ans;
    }
};