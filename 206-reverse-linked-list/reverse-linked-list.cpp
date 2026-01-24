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
    ListNode* recursion(ListNode* node){
        if(node==NULL or node->next==NULL)return node;
        ListNode* newhead=recursion(node->next);
        node->next->next=node;
        node->next=NULL;
        return newhead;
    }
    ListNode* reverseList(ListNode* head) {
        return recursion(head);
    }
};