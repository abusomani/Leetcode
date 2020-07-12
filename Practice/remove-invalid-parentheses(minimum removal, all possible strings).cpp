/*
Remove the minimum number of invalid parentheses in order to make the input string valid. Return all possible results.

Note: The input string may contain letters other than the parentheses ( and ).

Input: "()())()"
Output: ["()()()", "(())()"]

Input: "(a)())()"
Output: ["(a)()()", "(a())()"]

Input: ")("
Output: [""]

*/
class Solution
{
public:
    vector<string> removeInvalidParentheses(string s)
    {
        int left = 0, right = 0;

        for (char ch : s)
        {
            if (ch == '(')
                left++;
            else if (ch == ')')
            {
                if (left != 0)
                    left--;
                else
                    right++;
            }
        }
        // now the left and right bracket count is the minimum number of respective brackets to be deleted
        unordered_set<string> St;
        generate(St, s, left, right, 0, 0, "");
        vector<string> ans(St.begin(), St.end());
        return ans;
    }
    void generate(unordered_set<string> &St, string s, int left, int right, int idx, int pair, string str)
    {
        if (idx == s.size())
        {
            if (left == 0 and right == 0 and pair == 0)
            {
                St.insert(str);
            }
            return;
        }
        if (s[idx] != '(' and s[idx] != ')')
            generate(St, s, left, right, idx + 1, pair, str + s[idx]);
        if (s[idx] == '(')
        {
            // can be excluded
            if (left > 0)
                generate(St, s, left - 1, right, idx + 1, pair, str);
            generate(St, s, left, right, idx + 1, pair + 1, str + s[idx]);
        }
        if (s[idx] == ')')
        {
            // can be excluded
            if (right > 0)
                generate(St, s, left, right - 1, idx + 1, pair, str);
            if (pair > 0) // always try to make it balanced
                generate(St, s, left, right, idx + 1, pair - 1, str + s[idx]);
        }
    }
};