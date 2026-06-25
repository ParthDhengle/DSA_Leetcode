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
    ListNode* partition(ListNode* head, int x) {
        if(!head)return NULL;
        ListNode* dummy=new ListNode(-1);
        dummy->next=head;

        ListNode* less=dummy;

        ListNode *curr=head;
        while(curr and curr->val<x){
            less=curr;
            curr=curr->next;
        }
        ListNode * great=curr;
        ListNode* prev=less;
        while(curr){
            if(curr->val <x){
                ListNode* next=curr->next;
                less->next=curr;
                curr->next=great;
                prev->next=next;
                less=curr;
                curr=prev;
            }
            prev=curr;
            curr=curr->next;
        }
        return dummy->next;
    }
};