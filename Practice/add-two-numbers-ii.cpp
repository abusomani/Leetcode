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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        stack<int> A, B;
        while (l1)
            A.push(l1->val), l1 = l1->next;
        while (l2)
            B.push(l2->val), l2 = l2->next;

        // add to beginning for no final reversal
        ListNode *curr = nullptr;
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

            ListNode *newHead = new ListNode(sum % 10);
            newHead->next = curr;
            curr = newHead;
            carry = sum / 10;
        }

        return curr;
    }
};