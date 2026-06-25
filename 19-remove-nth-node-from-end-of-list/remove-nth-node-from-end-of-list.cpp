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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len=0;
        ListNode* curr=head;
        while(curr){
            curr=curr->next;
            len++;
        }
        if(len<=1)return NULL;

        int position=len-n;
        if(position<0)return head;


        int i=0;

        ListNode* dummy=new ListNode(-1);
        curr=dummy;
        curr->next=head;
        while(i<position){
            curr=curr->next;
            i++;
        }
        curr->next=curr->next->next;
        return dummy->next;
    }
};