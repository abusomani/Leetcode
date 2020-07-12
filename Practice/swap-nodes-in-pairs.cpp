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
    ListNode *swapPairs(ListNode *head)
    {
        if (!head or !head->next)
            return head;

        ListNode *firstNode = head, *secondNode = head->next;
        firstNode->next = swapPairs(head->next->next);
        secondNode->next = firstNode;

        return secondNode;
    }
};