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
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *forward = head, *backward = head, *prev = nullptr;
        while (--n)
            forward = forward->next;

        while (forward->next)
        {
            prev = backward;
            backward = backward->next;
            forward = forward->next;
        }
        if (prev)
        {
            prev->next = backward->next;
            delete backward;
        }
        else
        {
            prev = head;
            head = head->next;
            delete prev;
        }
        return head;
    }

    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *slow = dummy, *fast = dummy;
        for (int i = 1; i <= n; i++)
            fast = fast->next;

        while (fast->next)
        {
            slow = slow->next;
            fast = fast->next;
        }

        slow->next = slow->next->next;
        return dummy->next;
    }
};