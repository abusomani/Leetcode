// Time complexity =  O(N×4^N)
class Solution
{
public:
    void dfs(string &s, int idx, long target, long cv, long pv, string curr, vector<string> &res)
    {
        if (idx == s.size() and cv == target)
        {
            res.push_back(curr);
            return;
        }
        else
        {
            // all possible substrings
            for (int len = 1; len <= s.size() - idx; len++)
            {
                string sub_str = s.substr(idx, len);
                // Tricky step for numbers starting with 0, as they would give redundant result
                if (len > 1 and sub_str[0] == '0')
                    continue;
                long num = stol(sub_str);
                if (idx == 0) // initialize
                    dfs(s, len, target, num, num, sub_str, res);
                else
                {
                    dfs(s, idx + len, target, cv + num, num, curr + "+" + sub_str, res);
                    dfs(s, idx + len, target, cv - num, -num, curr + "-" + sub_str, res);
                    dfs(s, idx + len, target, cv - pv + pv * num, pv * num, curr + "*" + sub_str, res);
                }
            }
        }
    }
    vector<string> addOperators(string s, int target)
    {
        vector<string> res;
        dfs(s, 0, target, 0, 0, "", res);
        return res;
    }
};