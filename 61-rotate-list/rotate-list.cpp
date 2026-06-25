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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head)return NULL;
        int len=0;
        ListNode* curr=head;
        while(curr->next){
            curr=curr->next;
            len++;
        }
        len++;
        k=k%len;
        if(k==0)return head;

        curr->next=head;
        ListNode* prev=curr;
        curr=head;
        int count=0;

        while(count<(len-k)){
            prev=curr;
            curr=curr->next;
            count++;
        }
        prev->next=NULL;
        return curr;
    }
};