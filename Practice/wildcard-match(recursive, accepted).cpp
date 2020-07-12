class Solution
{
private:
    vector<vector<int>> dp;

    void initDP(string s, string p)
    {
        dp.reserve(s.size() + 1);
        vector<int> uninitialized(p.size() + 1, -1);
        for (int i = 0; i <= s.size(); i++)
            dp.push_back(uninitialized);
    }

public:
    string cleanup(string p)
    {
        string str = "#";
        for (auto c : p)
        {
            if (c == '*' and str.back() == '*')
                continue;
            str += c;
        }
        return str.substr(1);
    }
    bool dfs(const string &s, int idS, const string &p, int idP)
    {
        if (dp[idS][idP] != -1)
            return dp[idS][idP];

        bool matched = false;
        if (p.size() == idP)
            matched = (s.size() == idS);
        else
        {
            if (p[idP] == '*')
                matched = dfs(s, idS, p, idP + 1) or (idS < s.size() and dfs(s, idS + 1, p, idP));
            else
            {
                bool char_catched = false;
                if (idS < s.size() && (s[idS] == p[idP] || p[idP] == '?'))
                {
                    char_catched = true;
                }
                matched = char_catched && dfs(s, idS + 1, p, idP + 1);
            }
        }
        return dp[idS][idP] = matched;
    }
    bool isMatch(string s, string p)
    {
        p = cleanup(p); // remove continuous *s with only 1 *
        initDP(s, p);
        return dfs(s, 0, p, 0);
    }
};