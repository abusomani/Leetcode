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
private:
    ListNode *newHead = nullptr;

public:
    void reverse(ListNode *head)
    {
        if (!head or !head->next)
        {
            newHead = head;
            return;
        }
        reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
    }
    ListNode *reverseList(ListNode *head)
    {
        reverse(head);
        return newHead;
    }

    ListNode *reverseListSameMethod(ListNode *head)
    {
        if (!head or !head->next)
            return head;
        ListNode *p = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return p;
    }
};