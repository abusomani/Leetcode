/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// Time complexity => O(NlogN)
class Solution
{
public:
    TreeNode *sortedListToBST(ListNode *head)
    {
        if (!head)
            return nullptr;
        return toBST(head, nullptr);
    }
    TreeNode *toBST(ListNode *start, ListNode *end)
    {
        ListNode *slow = start, *fast = start;

        if (start == end)
            return nullptr;

        while (fast != end and fast->next != end)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        TreeNode *root = new TreeNode(slow->val);
        root->left = toBST(start, slow);
        root->right = toBST(slow->next, end);
        return root;
    }
};