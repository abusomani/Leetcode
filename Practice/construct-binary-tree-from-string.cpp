/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    int idx = 0;
public:
    TreeNode* str2tree(string s) {
        if(s.empty() or idx >= s.size())
            return nullptr;
        int num = 0;
        bool isNegative = false;
        if(s[idx] == '-')
            isNegative = true, idx++;
        while(idx < s.size() and isdigit(s[idx]))
            num = num*10 + (s[idx++]-'0');
        if(isNegative)
            num = -num;
        TreeNode * root = new TreeNode(num);
        if(idx < s.size() && s[idx] == '(') {
		    idx++;
		    root->left = str2tree(s);
		    idx++; // skip the wrapping )
        }
        if(idx < s.size() && s[idx] == '(') {
            idx++;
            root->right = str2tree(s);
            idx++; //skip the wrapping )
        }
        return root;
    }
};