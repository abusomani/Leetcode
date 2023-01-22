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
    int length(ListNode *head)
    {
        int len = 0;
        while (head)
        {
            len++;
            head = head->next;
        }
        return len;
    }

public:
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        ListNode dummy(0);
        ListNode *pre = &dummy;
        dummy.next = head;
        int len = length(head);
        for (int i = 0; i < len / k; i++)
        {
            for (int j = 1; j < k; j++)
            {
                ListNode *temp = pre->next;
                pre->next = head->next;
                head->next = head->next->next;
                pre->next->next = temp;
            }
            pre = head;
            head = head->next;
        }

        return dummy.next;
    }
};