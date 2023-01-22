class Solution
{
private:
    void dfs(string &s, int idx, int left, int right, int pair, string curr, set<string> &valid)
    {
        if (idx == s.size())
        {
            if (left == right and left == 0 and pair == 0)
                valid.insert(curr);
            return;
        }
        // directly recurse for ahead
        if (isalnum(s[idx]))
            dfs(s, idx + 1, left, right, pair, curr + s[idx], valid);
        else
        {
            if (s[idx] == '(')
            {
                // if we can delete, then recurse by deleting
                if (left > 0)
                    dfs(s, idx + 1, left - 1, right, pair, curr, valid);
                // else if we add this brace, increase another counter pair
                dfs(s, idx + 1, left, right, pair + 1, curr + '(', valid);
            }
            else if (s[idx] == ')')
            {
                // if we can delete, then recurse by deleting
                if (right > 0)
                    dfs(s, idx + 1, left, right - 1, pair, curr, valid);
                // we add closing brace, if a matching opening was added, identified by pair's value
                if (pair > 0)
                    dfs(s, idx + 1, left, right, pair - 1, curr + ')', valid);
            }
        }
    }

public:
    vector<string> removeInvalidParentheses(string s)
    {
        int left = 0, right = 0;
        for (auto &c : s)
        {
            if (c == '(')
                left++;
            else if (c == ')')
            {
                if (left > 0)
                    left--;
                else
                    right++;
            }
        }
        // now left + right are total number of invalid braces
        set<string> valid;
        dfs(s, 0, left, right, 0, "", valid);
        return vector<string>(valid.begin(), valid.end());
    }
};