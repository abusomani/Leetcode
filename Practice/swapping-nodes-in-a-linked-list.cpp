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
    ListNode* swapNodes(ListNode* head, int k) {
        vector<int> V;
        while(head)
            V.push_back(head->val), head = head->next;
        k--;
        swap(V[k], V[(int)V.size()-k-1]);
        ListNode dummy(0);
        ListNode *pre = &dummy;
        for(auto &val : V)
        {
            pre->next = new ListNode(val);
            pre = pre->next;
        }
        return dummy.next;
    }
};