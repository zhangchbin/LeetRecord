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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* tmp = new ListNode;
        ListNode* root = new ListNode;
        if(l1==nullptr && l2!=nullptr) root = l2;
        else if(l1!=nullptr && l2 == nullptr) root = l1;
        else if(l1 == nullptr && l2 == nullptr) root = NULL;
        else{

            if(l1->val < l2->val) root = l1, l1=l1->next;
            else root=l2, l2=l2->next;
            tmp=root;

            while(l1 != NULL || l2 != NULL){
                if(l1 == NULL){
                    tmp->next=l2;
                    break;
                }
                if(l2 == NULL){
                    tmp->next=l1;
                    break;
                }
                if(l1->val < l2->val){
                    tmp->next = l1;
                    l1 = l1->next;
                    tmp=tmp->next;
                }
                else{
                    tmp->next = l2;
                    l2=l2->next;
                    tmp=tmp->next;
                }
            }
        }
        return root;
    }
};
