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
        // 0->1->2->3

        // 0<-1<-2-3

        // prev = 3
        // curr = 3-2-1-0 | null
        // temp = null
        if(!head) return NULL;

        ListNode* prev = head;
        ListNode* x=head;
        ListNode* curr = prev->next;
        if(!curr){ // only 1 node in the list
            return prev;
        }

        while(curr){
            auto temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr=temp;
        }   

        x->next = NULL;

        return prev;
    }
};
