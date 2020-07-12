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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode * head = new ListNode(0);
        ListNode * dummy = head;
        int carry = 0;
        while(l1 != NULL or l2 != NULL or carry)
        {
            int sm = carry;
            if(l1)
            {
                sm += l1->val;
                l1 = l1->next;
            }
            if(l2)
            {
                sm += l2->val;
                l2 = l2->next;
            }
            dummy->next = new ListNode(sm%10);
            dummy = dummy->next;
            carry = sm /10;
        }
        return head->next;
    }
};