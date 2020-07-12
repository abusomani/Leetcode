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
    ListNode *mergeTwoList(ListNode *a, ListNode *b)
    {
        if (a == NULL)
            return b;
        if (b == NULL)
            return a;

        if (a->val <= b->val)
        {
            a->next = mergeTwoList(a->next, b);
            return a;
        }

        else
        {
            b->next = mergeTwoList(a, b->next);
            return b;
        }
    }

    struct compare
    {
        bool operator()(const ListNode *a, const ListNode *b)
        {
            return a->val > b->val;
        }
    };

    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        int N = lists.size();
        if (N == 0)
            return NULL;

        ListNode dummy(0);
        ListNode *res = &dummy;

        priority_queue<ListNode *, vector<ListNode *>, compare> PQ;

        for (int i = 0; i < N; i++)
            if (lists[i])
                PQ.push(lists[i]);

        while (!PQ.empty())
        {
            ListNode *a = PQ.top();
            PQ.pop();

            // get the node, assign it to result's next and increment res to next for chaining
            res->next = a;
            res = res->next;

            if (a->next)
            {
                PQ.push(a->next);
            }
        }

        return dummy.next;
        // ListNode * finalList = lists[0];
        // for(int i=1;i<N;i++)
        //     finalList = mergeTwoList(lists[i],finalList);
        // return finalList;
    }
};