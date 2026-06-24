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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* curr=head;

        ListNode * save_start=new ListNode(-1);
       int groups=0;
        while(curr){
            ListNode* start=curr;
            int counter=0;
            groups++;
            cout<<"group : "<<groups;
            for(int i=0;i<k;i++){
                if(!curr){break;}
                curr=curr->next;
                counter++;
            }
            if(counter<k){break;}
            counter=0;
            curr=start;
            ListNode* prev=NULL;
            for(int i=0;i<k;i++){
                ListNode* next = curr->next;
                curr->next=prev;
                prev=curr;
                curr=next;
                counter++;
            }
            if(groups==1){
                head=prev;
            }
            start->next=curr;
            save_start->next=prev;
            save_start=start;

        }
        return head;
    }
};