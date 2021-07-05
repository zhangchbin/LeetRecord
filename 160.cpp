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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* slow = headA, *fast = headB;
        int stepA = 0, stepB = 0;
        while(slow != fast){
            if(slow != NULL) slow = slow->next;
            else if(!stepA) slow = headB, stepA++;
            if(fast != NULL) fast = fast->next;
            else if(!stepB) fast = headA, stepB++;
        }
        return slow;
    }
};
