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
    ListNode* dfs(ListNode* p){
        
        if(p -> next == nullptr) return p;
        ListNode* tmp = dfs(p->next);
        p->next->next = p;
        p -> next = nullptr;
        return tmp;
    }

    ListNode* reverseList(ListNode* head) {
        if(head == nullptr) return nullptr;
        head = dfs(head);
        return head;
    }
};
