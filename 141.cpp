/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        
        ListNode* slow = head, *fast = head;
        int i=0;
        while(slow != fast || !i){
            i++;
            if(slow!=NULL) slow=slow->next;
            if(fast!=NULL){
                if(fast->next != NULL) fast=fast->next->next;
                else fast=fast->next;
            }
        }
        if(slow==NULL) return false;
        else return true;

    }
};
