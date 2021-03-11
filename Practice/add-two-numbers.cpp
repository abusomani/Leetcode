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
        ListNode dummy(0);
        ListNode * pre = &dummy;
        int sm = 0, carry = 0;
        while(l1 or l2 or carry) {
            sm = carry;
            if(l1)
                sm += l1->val, l1 = l1->next;
            if(l2)
                sm += l2->val, l2 = l2->next;
            carry = sm/10;
            sm = sm % 10;
            pre->next = new ListNode(sm);
            pre = pre->next;
        }
        return dummy.next;
    }
};