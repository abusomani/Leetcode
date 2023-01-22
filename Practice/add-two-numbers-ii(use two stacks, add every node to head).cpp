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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        stack<int> A, B;
        ListNode *a = l1, *b = l2;
        while (a)
        {
            A.push(a->val);
            a = a->next;
        }

        while (b)
        {
            B.push(b->val);
            b = b->next;
        }

        ListNode *dummy = nullptr;
        int sum = 0, carry = 0;
        while (!A.empty() or !B.empty() or carry)
        {
            sum = carry;
            if (!A.empty())
            {
                sum += A.top();
                A.pop();
            }
            if (!B.empty())
            {
                sum += B.top();
                B.pop();
            }
            ListNode *newNode = new ListNode(sum % 10);
            newNode->next = dummy;
            dummy = newNode;
            carry = sum / 10;
        }

        return dummy;
    }
};