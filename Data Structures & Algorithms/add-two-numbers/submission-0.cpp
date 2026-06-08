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
       /*
            l1 = 2-3-4-6
            l2 = 0-9
            carry = 1
            head = 2
            ans = 2-2
            sum = 12
            digit=2
            l1/remaining= 4
            l2= X

       */ 

            int carry=0;
            ListNode* ans=NULL;
            ListNode* head=ans;

            while(l1 && l2){
                int sum= l1->val + l2->val+carry;
                carry = sum/10;
                auto digit = sum%10;
                if(!ans){
                    ans = new ListNode(digit);
                    head=ans;
                } else {
                    ans->next = new ListNode(digit);
                    ans = ans->next;
                }
                l1 = l1->next;
                l2 = l2->next;
            } 

            auto remaining=l1?l1:l2;
            while(remaining){
                int sum= remaining->val+carry;
                carry = sum/10;
                auto digit = sum%10;
                ans->next = new ListNode(digit);
                ans = ans->next;
                remaining = remaining->next;
            }

            if (carry){
                ans->next = new ListNode(carry);
            }

            return head;
    }
};
