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
    ListNode* mergeList(ListNode*left, ListNode* right){
        ListNode* ptr=new ListNode(0);
        ListNode* curr=ptr;

        while(left!=NULL and right!=NULL){
            if(left->val <=right->val){
                curr->next=left;
                left=left->next;
            }else{
                curr->next=right;
                right=right->next;
            }
            curr=curr->next;
        }
        if(left!=NULL){
            curr->next=left;
        }
        if(right!=NULL){
            curr->next=right;
        }
        return ptr->next;
    }
    ListNode* sortList(ListNode* head) {
        if(head==NULL or head->next==NULL){
            return head;
        }
        ListNode* temp;
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast!=NULL and fast->next!=NULL){
            fast=fast->next->next;
            temp=slow;
            slow=slow->next;
        }
        temp->next=NULL;
        ListNode* left=sortList(head);
        ListNode* right=sortList(slow);

        return mergeList(left,right);
    }
};