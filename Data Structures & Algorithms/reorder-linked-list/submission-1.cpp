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
    void reorderList(ListNode* head) {
        if(!head || !head->next || !head->next->next) return ;
        
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast){
            slow = slow->next;
            fast = fast->next? fast->next->next: NULL;
        }

        ListNode* prev = NULL;

        ListNode* curr = slow;
        while(curr){
            auto temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }

        ListNode* head2 = prev;
        ListNode* headItr = head;    
        while(headItr && head2){
            auto temp = headItr->next;
            headItr->next = head2;
            auto temp2 = head2->next;
            head2->next =temp;
            head2 = temp2;
            headItr = temp;
        }
        if(headItr){
            headItr->next = NULL;
        } else {
            head2->next = NULL;
        }

        // return head;

    }
};
