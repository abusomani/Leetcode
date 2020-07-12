#include <bits/stdc++.h>
using namespace std;
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/*
    Merge K lists using merge 2 list logic.
*/
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution
{
public:
    ListNode *mergeLists(ListNode *l1, ListNode *l2)
    {
        if (!l1)
            return l2;
        if (!l2)
            return l1;
        if (l1->val <= l2->val)
        {
            l1->next = mergeLists(l1->next, l2);
            return l1;
        }
        else
        {
            l2->next = mergeLists(l1, l2->next);
            return l2;
        }
    }
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        if (lists.size() == 0)
            return NULL;
        if (lists.size() == 1)
            return lists[0];

        ListNode *M = mergeLists(lists[0], lists[1]);
        for (int i = 2; i < lists.size(); i++)
        {
            M = mergeLists(M, lists[i]);
        }
        return M;
    }
};