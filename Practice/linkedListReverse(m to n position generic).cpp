//https://assets.leetcode.com/static_assets/discuss/uploads/files/1490008792563-reversed_linked_list.jpeg
class Solution
{
public:
    ListNode *reverseBetween(ListNode *head, int m, int n)
    {
        if (m == n)
            return head;
        n -= m;
        ListNode dummy(0);
        ListNode *pre = &dummy;
        pre->next = head;

        //after this pre points to previous of the starting node.
        while (--m)
            pre = pre->next;

        ListNode *pstart = pre->next; // starting node
        while (n--)
        {
            ListNode *tmp = pstart->next;
            pstart->next = tmp->next;
            tmp->next = pre->next;
            pre->next = tmp;
        }

        return dummy.next;
    }
};