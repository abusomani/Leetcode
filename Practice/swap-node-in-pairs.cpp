/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(!head or !head->next)
            return head;
        
        ListNode* firstNode = head, *secondNode = head->next;
        firstNode->next = swapPairs(head->next->next);
        secondNode->next = firstNode;
        
        return secondNode;
    }
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution1
{
public:
    ListNode *swapPairs(ListNode *head)
    {
        if (!head)
            return NULL;
        ListNode tmp(0);
        tmp.next = head;
        ListNode *pre = &tmp, *cur = head;
        while (cur && cur->next)
        {
            pre->next = cur->next;
            pre = pre->next;
            cur->next = pre->next;
            pre->next = cur;
            pre = cur;
            cur = cur->next;
        }
        return tmp.next;
    }
};