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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head or k == 0)
            return head;
        vector<int> V;
        ListNode *curr = head;
        while(curr != nullptr) {
            V.push_back(curr->val);
            curr = curr->next;
        }
        int N = V.size();
        k %= N;
        int idx = N-k;
        curr = head;
        while(curr != nullptr) {
            curr->val = V[idx%N];
            curr = curr->next;
            idx = (idx + 1) %N;
        }
        return head;
    }
};