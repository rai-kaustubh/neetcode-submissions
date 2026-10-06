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
        ListNode* dummy = new ListNode(-1);
        dummy->next=head;
        ListNode* curr = head, *prev=dummy;
        while(curr) {
            auto [returnPrev, returnTemp] = reverseK(curr, k);
            // if(returnTemp == NULL) break;
            prev->next = returnPrev;
            while(returnPrev->next){
                returnPrev=returnPrev->next;
            }
            returnPrev->next = returnTemp;
            prev = returnPrev;
            curr = returnTemp;
        }

        return dummy->next;
    }

    // 1, 2
    pair<ListNode*, ListNode*> reverseK(ListNode* head, int k){
        int count = 1;
        ListNode* curr = head;

        while(curr && count<=k){
            curr = curr->next;
            count++;
        }

        if(!curr && count<=k){
            return {head, NULL};
        }
        
        ListNode* prev = NULL;
        count =1;
        curr= head;
        
        ListNode* temp = NULL;
        while(curr && count<=k){
            temp = curr->next;
            curr->next= prev;
            prev = curr;
            curr = temp;
            count++;
        }

        return {prev, temp};
    }
};
/*
Input: head = [1,2,3,4,5,6], k = 2


list= -1-2-1-3-X
curr = 1
prev = -1-2-1-X
returnPrev = 3-X
returnTemp = NULL


prev=4-3-X
curr=1
// 4-3-X
count=3
temp =5








*/