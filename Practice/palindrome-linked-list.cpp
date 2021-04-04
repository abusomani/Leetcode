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
    bool isPalindrome(ListNode* head) {
        vector<int> V;
        while(head)
            V.push_back(head->val), head = head->next;
        vector<int> M(V.begin(), V.end());
        reverse(M.begin(), M.end());
        return V == M;
    }
};