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
    ListNode* reverseList(ListNode* head) {
        ListNode* Curr=head;
        ListNode* Next=head;
        ListNode* prev=NULL;
        while(Curr!=NULL){
            Next=Next->next;
            Curr->next=prev;
            prev=Curr;
            Curr=Next;
        }
        return prev;
    }
};