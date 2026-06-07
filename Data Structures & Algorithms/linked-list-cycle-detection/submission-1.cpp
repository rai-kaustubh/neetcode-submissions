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
    /*
        1-2-3
           \|
            4

        1-2

    
    
    */    
    bool hasCycle(ListNode* head) {
        if(!head) return false;
        ListNode* t = head;
        ListNode* h=head->next;

        while(h!=NULL && h->next!=NULL){
            if(t==h){
                return true;
            }

            t=t->next;
            h = h->next?h->next->next:NULL;
        }

        return false;
    }   
};
