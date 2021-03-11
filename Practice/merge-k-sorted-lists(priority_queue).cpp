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
struct compare
{
    bool operator()(const ListNode *a, const ListNode *b)
    {
        return a->val > b->val;
    }
};
class Solution
{
public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        ListNode dummy(0);
        ListNode *pre = &dummy;
        priority_queue<ListNode *, vector<ListNode *>, compare> PQ;
        for (auto &list : lists)
            if (list)
                PQ.push(list);
        while (!PQ.empty())
        {
            ListNode *node = PQ.top();
            PQ.pop();
            pre->next = node;
            pre = pre->next;
            if (node->next)
                PQ.push(node->next);
        }
        return dummy.next;
    }
};