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
        Node* curr = head;
        unordered_map<int, Node*> uo_map;
        while (curr) {
            Node* dummy = new Node(curr->val);
            Node* next = curr->next;
            // uo_map[curr->val] = dummy;
            curr->next = dummy;
            dummy->next = next;
            curr = next;
        }

        curr=head;
        // random pointer assignment
        while(curr){
            curr->next->random = curr->random?curr->random->next:NULL;
            curr = curr->next->next;
        }

        // separate the 2;
        Node* head2=head->next;
        Node* p1 =head;
        Node* p2 =head2;

        while(p1 && p2){
            p1->next = p1->next->next;
            p2->next = p2->next?p2->next->next:NULL;
            p1 = p1->next;
            p2=p2->next;
        }

        return head2;


    }
};
/*
1-1'-2-2'-3-3'
1-2-3
1'-2'

*/
