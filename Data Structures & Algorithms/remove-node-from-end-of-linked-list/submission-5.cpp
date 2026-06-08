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
    for n>=n/2   
        1-2-3-4
        n=1
        temp = 4
        itr = 3

    */
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head->next || !head) return NULL;

        int len=0;
        auto i = head;
        while(i){
            i=i->next;
            len++;
        }

        // if (n>=len/2){
        //     n = n%(len/2);
        // }
        if(n == len){
            head = head->next;
            return head;
        }

        auto temp = head;
        while(n--){
            temp = temp->next;
        }
       
        auto itr = head;
        while(temp->next){
            itr = itr->next;
            temp =temp->next;
        }

        itr->next = itr->next->next;
        return head;
    }
};
