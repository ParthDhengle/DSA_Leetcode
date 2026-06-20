/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head)return NULL;
        Node* curr=head;

        while(curr!=NULL){
            Node * nn=new Node(curr->val);
            nn->next=curr->next;
            curr->next=nn;
            curr=curr->next->next;
        }
        curr=head;
        while(curr!=NULL){
            if(curr->random){
                curr->next->random=curr->random->next;
            }
            curr=curr->next->next;
        }
        Node* oldHead=head;
        Node* newHead=head->next;
        Node* oldCurr=oldHead;
        Node* newCurr=newHead;

        while(oldCurr!=NULL){
            oldCurr->next=oldCurr->next->next;
            newCurr->next=newCurr->next ? newCurr->next->next:NULL;
            oldCurr=oldCurr->next;
            newCurr=newCurr->next;
        }
        return newHead;
    }
};