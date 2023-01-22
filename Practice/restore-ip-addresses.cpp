class Solution
{
public:
    void dfs(string &s, int idx, string curr, int dots, vector<string> &res)
    {
        if (idx > s.size() or dots < 0)
            return;
        if (idx == s.size() and dots == 0)
        {
            res.push_back(curr);
            return;
        }
        else
        {
            for (int len = 1; len <= 3; len++)
            {
                if (idx + len <= s.size())
                {
                    string sub = s.substr(idx, len);
                    if (sub[0] == '0' and len > 1)
                        continue;
                    if (stoi(sub) <= 255)
                    {
                        string newcurr = curr.empty() ? sub : curr + "." + sub;
                        dfs(s, idx + len, newcurr, curr.empty() ? dots : dots - 1, res);
                    }
                }
            }
        }
    }
    vector<string> restoreIpAddresses(string s)
    {
        vector<string> res;
        dfs(s, 0, "", 3, res);
        return res;
    }
};