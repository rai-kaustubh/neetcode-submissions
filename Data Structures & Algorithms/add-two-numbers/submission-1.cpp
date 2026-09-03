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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* itr1 = l1;
        ListNode* itr2 = l2;
        ListNode* dummy = new ListNode(-1);
        ListNode* dummyHead = dummy;

        int carry=0;
        
        while(itr1 && itr2){
            int sum = itr1->val + itr2->val+carry;
            carry = sum/10;
            ListNode* curr = new ListNode(sum%10);
            dummy->next = curr;
            dummy = dummy->next;
            itr1 = itr1->next;
            itr2 = itr2->next;
        }

        ListNode* leftOver = itr1?itr1:itr2;
        if(leftOver){
           while(leftOver){
            int sum = leftOver->val+carry;
            carry = sum/10;
            ListNode* curr = new ListNode(sum%10);
            dummy->next = curr;
            dummy = dummy->next;
            leftOver=leftOver->next;
           } 
        }

        if(carry){
            dummy->next = new ListNode(carry);
        }

        return dummyHead->next;
    }
};
