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
    ListNode* insertionSortList(ListNode* head) {
        vector<int> V;
        ListNode * curr = head;
        while(curr != nullptr)
            V.push_back(curr->val), curr = curr->next;
        
        sort(V.begin(), V.end());
        curr = head;
        for(auto &val : V)
            curr->val = val, curr = curr->next;
        
        return head;    
    }
};