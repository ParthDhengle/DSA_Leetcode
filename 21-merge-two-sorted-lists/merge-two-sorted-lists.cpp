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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode * NN=new ListNode();
        ListNode * head=NN;

        while(list1 and list2){
            int n;
            if(list1->val <= list2->val){
                n=list1->val;
                list1=list1->next;
            }else{
                n=list2->val;
                list2=list2->next;
            }
            NN->next=new ListNode(n);
            NN=NN->next;
        }
        if(list1){
            NN->next=list1;
        }
        if(list2){
            NN->next=list2;
        }
        return head->next;
    }
};