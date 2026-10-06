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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0) return {};
        // if(lists.size()==1) return {}

        while(lists.size()>1){
            vector<ListNode*> listsCopy;
            listsCopy.clear();

            for(int i=0;i<lists.size(); i+=2){
                ListNode* l1 = lists[i];
                if(i+1<lists.size()){
                    ListNode* l2 =lists[i+1];
                    ListNode* head = merge(l1, l2);
                    listsCopy.push_back(head);
                } else{
                    listsCopy.push_back(l1);
                }
            }
            lists.clear();
            lists = listsCopy;
        }

        return lists[0];
    }

    ListNode* merge(ListNode* l1, ListNode* l2){
        ListNode* dummy = new ListNode(-1);
        ListNode* curr =dummy;

        while(l1 && l2){
            if(l1->val<=l2->val){
                curr->next= l1;
                l1 = l1->next;
            } else{
                curr->next=l2;
                l2=l2->next;
            }
            curr=curr->next;
        }

        if(l1){
            curr->next= l1;
        } else{
            curr->next = l2;
        }

        return dummy->next;
    }
};
/*
    // lists = [[1,2,4],[1,3,5],[3,6]]
    lists = [[1,1,2,3,4],[3,6]]
    l1 = 1,1,2,3,4
    l2 = 3,6
    listsCopy = 1,1,2,3,3,4,6
    lis

*/
