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
        ListNode* curr=head, *prev=NULL;
        while(curr){
            auto temp = curr->next;
            curr->next = prev;
            prev=curr;
            curr = temp;
        }
        return prev;
    }

};
/*
head = X[0,1,2,3]
prev = 0
curr = 1
temp = 2
list: 1->0->X

while(curr){
    auto temp = curr->next;
    curr->next = prev;
    prev=curr;
    curr = temp;
}
*/

