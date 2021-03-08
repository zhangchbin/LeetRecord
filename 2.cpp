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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int val = (l1->val + l2->val) % 10;
        int up = (l1->val + l2->val) / 10;
        ListNode* ans = new ListNode(val);
        ListNode* cur = ans;
        while(l1->next != NULL && l2->next != NULL){
            l1 = l1->next;
            l2 = l2->next;
            val = (l1->val + l2->val + up) % 10;
            up = (l1->val + l2->val + up) / 10;
            ListNode* tmp = new ListNode(val);
            cur->next=tmp;
            cur = cur->next;
        }
        while(l1->next != NULL){
            l1 = l1->next;
            val = (l1->val + up) % 10;
            up = (l1->val + up) / 10;
            ListNode* tmp = new ListNode(val);
            cur->next=tmp;
            cur=cur->next;
        }
        while(l2->next != NULL){
            l2 = l2->next;
            val = (l2->val + up) % 10;
            up = (l2->val + up) / 10;
            ListNode* tmp = new ListNode(val);
            cur->next=tmp;
            cur=cur->next;
        }
        if(up != 0){
            ListNode*tmp = new ListNode(up);
            cur->next = tmp;
        }
        return ans;
    }
};
