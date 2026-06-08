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

/*
    // itr = 7
    

*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return head;
        // insert elements
        auto itr = head;
        while(itr){
            auto temp = itr->next;
            itr->next = new Node(itr->val);
            itr->next->next = temp;
            itr=temp;
        }
        // [3,null],[7,3],[4,0],[5,1]]
        /*
            itr = 3,null > 3', null > 7,3 > 7',null > 4,0 > 4',0 > 5,1 > 5',1 > X
            temp = X 
        */


        // copy random pointers
        itr = head;
        while(itr){
            if(itr->random){
                itr->next->random = itr->random->next; // copy random pointer
            } else{
                itr->next->random = NULL;
            }
            itr = itr->next->next;
        }
        // [3,null],[7,3],[4,0],[5,1]]
        //  3,null > 3', null > 7,3 > 7',null > 4,0 > 4',null > 5,1 > 5',null > X

        /*
            itr = 7,3
            temp = X 
        */

        // 3-3'-7-7'-4-4'-X 

        // 1->1'->2->2'-X
        // itr = 1-2
        // itr2 = 1'-2'



        // dissociate 2 lists
        itr=head;
        auto itr2 = head->next;
        auto headToReturn =itr2;

        while(itr){
            itr->next = itr->next->next;
            itr2->next = itr2->next?itr2->next->next:NULL;
            itr = itr->next;
            itr2 = itr2->next;
        }

        return headToReturn;
        
    }
};
