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
    ListNode* partition(ListNode* head, int x) {
        ListNode dummy(0), *pre = &dummy, *curr = head;
        while(curr)
        {
            if(curr->val < x)
            {
                pre->next = new ListNode(curr->val); 
                pre = pre->next;
                curr->val = INT_MAX;
            }
            curr = curr->next;
        }
        curr = head;
        while(curr != nullptr)
        {
            if(curr->val != INT_MAX)
                pre->next = new ListNode(curr->val), pre = pre->next;; 
            curr = curr->next;
        }
        return dummy.next;
    }
};