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
    vector<int> nextLargerNodes(ListNode *head)
    {
        stack<pair<int, int>> St;
        vector<int> ans;
        if (!head)
            return ans;

        ListNode *curr = head;
        while (curr != nullptr)
        {
            ans.push_back(curr->val);
            curr = curr->next;
        }

        for (int i = 0; i < ans.size(); i++)
        {
            if (St.empty() or ans[i] <= St.top().first)
            {
                St.push({ans[i], i});
                continue;
            }
            while (!St.empty() and St.top().first < ans[i])
            {
                ans[St.top().second] = ans[i];
                St.pop();
            }
            St.push({ans[i], i});
        }

        while (!St.empty())
        {
            ans[St.top().second] = 0;
            St.pop();
        }
        return ans;
    }
};