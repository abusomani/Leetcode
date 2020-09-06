class Solution
{
public:
    ListNode *getMid(ListNode *head)
    {
        ListNode *fast = head, *slow = head, *prev = nullptr;
        while (fast and fast->next)
        {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        return prev;
    }
    ListNode *rev(ListNode *head)
    {
        ListNode *curr = head, *next = nullptr, *p = nullptr;
        while (curr != nullptr)
        {
            next = curr->next;
            curr->next = p;
            p = curr;
            curr = next;
        }
        return p;
    }
    void reorderList(ListNode *head)
    {
        if (!head or !head->next)
            return;
        ListNode *mid = getMid(head);      // get previous of middle
        ListNode *second = rev(mid->next); // reverse the later half
        mid->next = nullptr;               // cut the links

        bool toggle = false;
        ListNode dummy(0);
        ListNode *pre = &dummy;
        while (head and second)
        {
            if (!toggle)
                pre->next = head, head = head->next;
            else
                pre->next = second, second = second->next;
            pre = pre->next;
            toggle = !toggle;
        }
        while (head)
            pre->next = head, head = head->next, pre = pre->next;
        while (second)
            pre->next = second, second = second->next, pre = pre->next;
        head = dummy.next;
    }
};