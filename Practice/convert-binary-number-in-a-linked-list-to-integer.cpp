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
    int getDecimalValue(ListNode *head)
    {
        int value = 0;
        ListNode *temp = head;
        while (temp != NULL)
        {
            value <<= 1;
            if (temp->val == 1)
            {
                ++value;
            }
            temp = temp->next;
        }
        delete temp;
        return value;
    }
};