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
// Time complexity = O(N)
// Space complexity =  O(logN)
class Solution
{
public:
    int listLength(ListNode *head)
    {
        int len = 0;
        while (head)
        {
            len++;
            head = head->next;
        }
        return len;
    }
    TreeNode *sortedListToBST(ListNode *head)
    {
        int sz = listLength(head);
        return inorder(head, 0, sz - 1);
    }
    TreeNode *inorder(ListNode *&head, int l, int r)
    {
        if (l > r)
            return nullptr;
        int mid = l + (r - l) / 2;

        TreeNode *left = inorder(head, l, mid - 1);
        TreeNode *root = new TreeNode(head->val);
        head = head->next;
        root->left = left;
        root->right = inorder(head, mid + 1, r);

        return root;
    }
};