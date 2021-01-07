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
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head or head->next == nullptr)
            return head;
        ListNode dummy(0);
        ListNode * pre = &dummy, *curr = head;
        while(curr) {
            ListNode *tmp = new ListNode(curr->val);
            curr = curr->next;
            bool isValid = true;
            while(curr && curr->val == tmp->val)
            {
                isValid = false;
                curr = curr->next;
            }
            if(isValid)
            {
                pre->next = tmp;
                pre = pre->next;
            }
        }
        return dummy.next;
    }
};

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
class Solution1
{
public:
    ListNode *deleteDuplicates(ListNode *head)
    {
        if (!head or head->next == nullptr)
            return head;
        ListNode dummy(0);
        ListNode *pre = &dummy, *curr = head;
        while (curr)
        {
            ListNode *nxt = curr->next;

            if (nxt and nxt->val == curr->val)
            {
                while (nxt and nxt->val == curr->val)
                {
                    nxt = nxt->next;
                }
            }
            else
                pre->next = curr, pre = pre->next, pre->next = nullptr;

            curr = nxt;
        }
        return dummy.next;
    }
};