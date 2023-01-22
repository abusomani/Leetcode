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
    ListNode *oddEvenList(ListNode *head)
    {
        if (!head or !head->next)
            return head;

        // first = head, second on next
        // each iteration, first->next = second->next, move first to its next
        // then second->next is present first's next
        // move second to its own next
        ListNode *first = head, *second = head->next, *headSecond = second;
        while (second and second->next)
        {
            first->next = second->next;
            first = first->next;

            second->next = first->next;
            second = second->next;
        }
        first->next = headSecond;
        return head;
    }
};