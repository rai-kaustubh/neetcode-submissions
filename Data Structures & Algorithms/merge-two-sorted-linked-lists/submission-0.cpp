class Solution {
   public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (!l1) {
            return l2;
        }

        if (!l2) {
            return l1;
        }
        
        ListNode* head = NULL;
        ListNode* prev = NULL;
        
        if (l1->val <= l2->val) {
            head = l1;
            prev = l1;
            l1 = l1->next;  // Changed from l1.next
        } else {
            prev = l2;
            head = l2;
            l2 = l2->next;  // Changed from l2.next
        }

        while (l1 && l2) {
            if (l1->val <= l2->val) {
                prev->next = l1;  // Changed from prev.next
                prev = l1;
                l1 = l1->next;    // Changed from l1.next
            } else {
                prev->next = l2;  // Changed from prev.next
                prev = l2;
                l2 = l2->next;    // Changed from l2.next
            }
        }

        if (!l1) {
            prev->next = l2;  // Changed from prev.next
        } else {
            prev->next = l1;  // Changed from prev.next
        }

        return head;
    }
};