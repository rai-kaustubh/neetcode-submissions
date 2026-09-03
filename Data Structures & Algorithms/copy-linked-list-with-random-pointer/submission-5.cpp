/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return head;

        // iterate over the list
        Node* itr = head;
        while(itr){
            Node* copy = new Node(itr->val);
            
            auto temp = itr->next;
            itr->next = copy;
            copy->next = temp;
            itr = temp;
        }

        itr = head;
        while(itr){
            itr->next->random = itr->random?itr->random->next:NULL;
            itr = itr->next->next;
        }
        
        itr = head;
        auto itr2 = head->next;
        auto head2 = itr2;

        while(itr && itr2){
            auto temp1 = itr2->next;
            auto temp2 = temp1?temp1->next:NULL;
            itr->next = temp1;
            itr2->next = temp2;

            itr = itr->next;
            itr2 = itr2->next;
        }

        return head2;

    }
};
