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
class Solution
{
public:
    ListNode *deleteDuplicates(ListNode *head)
    {
        if (!head)
            return head;
        ListNode dummy(INT_MAX);
        ListNode *pre = &dummy;
        while (head)
        {
            if (head->val != pre->val)
                pre->next = new ListNode(head->val), pre = pre->next, pre->next = nullptr;
            head = head->next;
        }
        return dummy.next;
    }
};