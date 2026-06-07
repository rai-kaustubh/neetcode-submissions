class Solution {
public:
    ListNode* reverseHalf(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* prev = NULL;
        ListNode* curr = slow->next;
        while(curr){ 
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        slow->next = NULL;  // Important: disconnect first half
        return prev;
    }

    void reorderList(ListNode* head) {
        ListNode* mid = reverseHalf(head);
        ListNode* p1 = head;
        ListNode* p2 = mid;
        while(p2){
            ListNode* temp = p1->next;
            ListNode* temp2 = p2->next;
            p1->next = p2;
            p2->next = temp;
            p1 = temp;
            p2 = temp2;
        }
    }
};