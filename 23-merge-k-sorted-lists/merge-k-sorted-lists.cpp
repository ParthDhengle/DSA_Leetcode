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

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pair<int,ListNode*> , vector<pair<int,ListNode*>> , greater<pair<int,ListNode*>> >min_heap;
        
        for(auto list:lists){
            if(list){
                min_heap.push({list->val,list});
            }
        }

        ListNode* dummy=new ListNode(-1);
        ListNode* head=dummy;

        while(!min_heap.empty()){
            ListNode* curr=min_heap.top().second;
            min_heap.pop();
            head->next=curr;
            head=head->next;

            if(curr->next){
                min_heap.push({curr->next->val,curr->next});
            }
        }
        return dummy->next;
    }
};