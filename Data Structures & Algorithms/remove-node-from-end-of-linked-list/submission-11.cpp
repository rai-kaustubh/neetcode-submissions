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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head) return head;
        if(!head->next) return NULL;
        ListNode* p2 = head;
        // n++;
        while(n-- && p2){
            p2=p2->next;
        }

        if(!p2) return head->next;
        
        ListNode* p1 = head, *prev =head;

        while(p2){
            p2 =p2->next;
            prev =p1;
            p1=p1->next;
        }

        prev->next = p1->next;
        return head;


    }
};
/*
head = [1,2,3,4,5,6], n = 5
n+1
p2=;
p1=2



*/