/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    ListNode *removeElements(ListNode *head, int val)
    {
        ListNode dummy(0);
        dummy.next = head;
        ListNode *prev = &dummy;
        ListNode *cur = prev->next;
        while (cur)
        {
            if (cur->val == val)
                prev->next = cur->next;
            else
                prev = prev->next;
            cur = cur->next;
        }
        return dummy.next;
    }

    ListNode *removeElements1(ListNode *head, int val)
    {
        ListNode *dummy = new ListNode(0);
        dummy->next = head;

        ListNode *prev = dummy, *toDelete = nullptr, *curr = head;
        while (curr)
        {
            if (curr->val == val)
            {
                prev->next = curr->next;
                toDelete = curr;
            }
            else
                prev = curr;
            curr = curr->next;
            if (toDelete)
            {
                delete toDelete;
                toDelete = nullptr;
            }
        }
        ListNode *ret = dummy->next;
        delete dummy;
        return ret;
    }
};