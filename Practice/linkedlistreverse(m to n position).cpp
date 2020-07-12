
class Solution
{
public:
    ListNode *reverseBetween(ListNode *head, int m, int n)
    {
        if (head == nullptr or n == 1)
            return head;

        ListNode *curr = head, *prev = NULL;
        int cnt = 1;
        while (cnt++ < m)
            prev = curr, curr = curr->next;
        if (prev != nullptr)
            prev->next = reverse(curr, n - m + 1);
        else
            head = reverse(curr, n - m + 1);
        return head;
    }

    ListNode *reverse(ListNode *head, int n)
    {
        ListNode *curr = head, *prev = NULL, *next = NULL;
        while (curr != NULL and n--)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head->next = curr;
        return prev;
    }
};