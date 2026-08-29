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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0);
        ListNode* itr = dummy;
        
        while(l1 && l2){
            if(l2->val > l1->val){
                itr->next = l1;
                l1 = l1->next;
            } else{
                itr->next = l2;
                l2 = l2->next;
            }
            itr = itr->next;
        }

        if(l1){
            itr->next = l1;
        } else{
            itr->next = l2;
        }

        return dummy->next;

    }
};
